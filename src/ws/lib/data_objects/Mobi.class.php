<?php
/**
  * classe di test 
  */
class Mobi{

	/**
	  * Thest Method Hello world
	  * @return string
	  */
	public function hello() {
		return "Hello World!";
	}
	
	/**
	  * Test Method print string
	  * @param string
	  * @return string
	  */
	public function printString($in) {
		return $in;
	}
	
	/**
	  * Recupera tutte le informazioni di un paziente a partire dall'id
	  * @param string id del paziente
	  * @return Patient
	  */
	public function getPatientById($id) {
		
		/* costruisce l'oggetto Patient e lo restituisce */
		$patient = new Patient();
		$patient->patientId = $id;
		$patient->anagrafica = $this->getReport($id);
		$patient->contacts = $this->getContacts($id);
		//$patient->medicalReport = $this->getMedicalReport($id); // scheda medica
		$patient->pathologies = $this->getPathologies($id);
		$patient->images = $this->getImages($id);
		$patient->visitHistory = $this->getVisitsHistory($id); // lista delle visite effettuate
		
		return $patient;
	}

	/**
	  * Esegue la ricerca di un paziente a partire da nome, cognome, comune di residenza e codice identificativo
	  * @param string nome del paziente
	  * @param string cognome del paziente
	  * @param string comune di residenza del paziente
	  * @param string codice identificativo del paziente
	  * @return SimplePatient[]
	  */
	public function	searchPatient($firstName, $lastName, $city, $patientCode) {
		/* costruisce la query di ricerca */
		if($patientCode == "")
			$query = "SELECT * FROM patient_registry WHERE "
    			."first_name like '%" . $firstName . "%' AND "
    			."last_name like '%" . $lastName . "%' AND "
				."city like '%" . $city . "%';";
				
		else
			$query = "SELECT * FROM patient_registry WHERE "
    				."first_name like '%" . $firstName . "%' AND "
    				."last_name like '%" . $lastName . "%' AND "
					."city like '%" . $city . "%' AND "
					."patient_code = '" . $patientCode . "'; ";
		//$query = "SELECT * FROM patient_registry WHERE first_name like '%". $firstName ."%';";
		
		/* si connette al database ed esegue la query di ricerca */
		$username="nurse";
		// $password="password";
		$database="live_app";
		mysql_connect("localhost",$username);
		@mysql_select_db($database) or die( "Unable to select database"); // TODO: and client???
 		$result = mysql_query($query);
 		$num = mysql_numrows($result);
 		mysql_close();
		
		/* cicla sui risultati e per ogni riga trovata costruisce l'oggetto SimplePatient e lo mette nell'array */
		$patientArray = Array(); 
		for($i=0; $i<$num; $i++){
			$patient = new SimplePatient();
			$patient->patientId = mysql_result($result,$i,"id");
			$patient->name = mysql_result($result,$i,"first_name");
			$patient->lastName = mysql_result($result,$i,"last_name");
			$patient->city = mysql_result($result,$i,"city");
			$patient->patientCode = mysql_result($result,$i,"patient_code");
			/* aggiongo l'oggetto i-esimo all'array */
			$patientArray[] = $patient;
		}

		/* restituisce l'array così costruito */
		return $patientArray;			
	} 
	
	/**
	  * Salva il file xml inviato dal client
	  * @param string id del paziente
	  * @param string codice tipologia di visita
	  * @param string file XML da salvare
	  * @param string time stamp di quando il client ha effettuato la visita
	  * @return void
	  */ 
	public function saveData($patientId, $visitCode, $data, $timeStamp) {
		/* if ../data doesn't exists, create it */
		if (!file_exists("../data"))
		{
			mkdir("../data");
		}
		/* if ../data/patients doesn't exists, create it */
		if (!file_exists("../data/patients"))
		{
			mkdir("../data/patients");
		}
		
		/* if ../data/patients/$patientId doesn't exists, create it */
		if (!file_exists("../data/patients/".$patientId))
		{
			mkdir("../data/patients/".$patientId);
		}
		
		/* if ../data/patients/$patientId/xml doesnt't exists, create it */
		if (!file_exists("../data/patients/".$patientId."/xml"))
		{
			mkdir("../data/patients/".$patientId."/xml");
		}
		
		/* save the data in XML file */
		$xmlFile = "../data/patients/".$patientId."/xml/".$visitCode."_".$timeStamp.".xml";
		$fh = fopen($xmlFile, 'w') or die("can't open file");
		fwrite($fh, $data);
		fclose($fh);
	}
	
	/**
	  * Salva una immagine inviata dal client
	  * @param string id del paziente
	  * @param string codice tipologia di visita
	  * @param string immagine codificata in base64
	  * @param string time stamp di quando il client ha effettuato la visita
	  * @return void
	  */ 
	public function saveImage($patientId, $visitCode, $base64Image, $timeStamp)
	{			
		/* if ../data/patients/$patientId/images doesn't exists, create it */
		if (!file_exists("../data/patients/".$patientId."/images"))
		{
			mkdir("../data/patients/".$patientId."/images");
		}
		
		/* if the directory to save the image doesn't exist (so this is the first image of the series), create it */
		$imageDir = "../data/patients/".$patientId."/images/".$visitCode."_".$timeStamp;
		if (!file_exists($imageDir))
		{
			mkdir($imageDir);
		}
		
		/* get the first file name available */
		$i=1;
		$fileExists = file_exists($imageDir."/1.jpg");
		$fileName = $imageDir."/1.jpg";
		while($fileExists)
		{
			$i = $i + 1;
			$fileName = $imageDir."/".$i.".jpg";
			$fileExists = file_exists($fileName);
		}
		
		/* sava the image */
		$decodedImage=base64_decode($base64Image);
		$restoredImage=imagecreatefromstring($decodedImage);
		imagejpeg($restoredImage,$fileName,100);
	}

	/* 
	 * FUNZIONI AUSILIARIE:
	 *	non invocabili dall'ensterno!
	 */
	 
	/* restituisce l'anagrafica del paziente identificato da $id */
	private function getReport($id) {
		/* si connette al database */
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni */
		$select = "SELECT * FROM patient_registry WHERE id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); // sempre un solo paziente perchè id univoco
		mysql_close();

		/* costruisce l'oggetto da restituire al client e lo ritorna */
		$anagrafica = new Anagrafica();
		$anagrafica->patientId = mysql_result($result,0,"id");
		$anagrafica->patientCode = mysql_result($result,0,"patient_code");
		$anagrafica->name = mysql_result($result,0,"first_name");
		$anagrafica->lastName = mysql_result($result,0,"last_name");  			
		$anagrafica->address = mysql_result($result,0,"address");
		$anagrafica->cap = mysql_result($result,0,"cap");
		$anagrafica->city = mysql_result($result,0,"city");
		$anagrafica->province = mysql_result($result,0,"province");
		$birth_dateObj = strtotime(mysql_result($result,0,"birth_date"));
		$anagrafica->birthDate = date("d", $birth_dateObj)."/".date("m", $birth_dateObj)."/".date("Y", $birth_dateObj);
		$anagrafica->GP = mysql_result($result,0,"GP"); // medico di base
		$anagrafica->CF = mysql_result($result,0,"CF"); // codice fiscale
		$anagrafica->profession = mysql_result($result,0,"profession");
		$anagrafica->birthLocation = mysql_result($result,0,"birth_location");
		$anagrafica->marital = mysql_result($result,0,"marital");

		return $anagrafica;
	}
	
	
	
	/* restituisce la lista contatti del paziente identificato da $id (se non ci sono contatti ritorna un array vuoto) */
	private function getContacts($id) {
		/* mi connetto al database */
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupero le informazioni */
		$select = "SELECT * FROM contact WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorro le righe ritornate dalla query e per ugnuna creo un oggetto Contact da mettere nell'array */
		$contactsArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$contact = new KeyValueObject();
			$contact->patientId = $id;
			$contact->objectId = mysql_result($result,$i,"id"); //contactId
			$contact->key = mysql_result($result,$i,"label");
			$contact->value = mysql_result($result,$i,"value");
			/* aggiongo l'oggetto i-esimo all'array */
			$contactsArray[] = $contact;
		}
		return $contactsArray;
	}
	
	/* restituisce la lista delle patologie del paziente (se non ci sono patologie ritorna un array vuoto) */
	private function getPathologies($id) {
		/* si connette al database */
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni */
		$select = "SELECT * FROM pathologies WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto KeyValueObject da mettere nell'array */
		$pathologiesArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$pathology = new KeyValueObject();
			$pathology->patientId = $id;
			$pathology->objectId = mysql_result($result,$i,"id"); // pathologyId
			$pathology->key = mysql_result($result,$i,"name");
			$pathology->value = mysql_result($result,$i,"description");
			/* aggiongo l'oggetto i-esimo all'array */
			$pathologiesArray[] = $pathology;
		}
		return $pathologiesArray;
	}
	
	/* restituisce la lista delle immagini associate al paziente identificato da $id */
	private function getImages($id) {
		/* si connette al database */
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");
		
		/* recupera le informazioni */
		$select = "SELECT * FROM images WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto ImageItem da mettere nell'array */
		/* se il paziente non ha immagini associate, restituisce un array vuoto */
		$imagesArray = Array();
		
		for($i=0; $i<$num; $i++){
			$image = new ImageItem();
			$image->imageId = mysql_result($result,$i,"id");
			$image->patientId = $id;
			$image->base64Preview = getImagePreview($image->imageId); // ritorna l'anteprima dell'immagine in base64
			$image->name = mysql_result($result,$i,"name");
			$image->imageNote = mysql_result($result,$i,"comment");
			/* aggiongo l'oggetto i-esimo all'array */
			$imagesArray[] = $image;
		}
		return $imagesArray;
	}
	
	/* restituisce la lista delle visite mediche effettuate dal paziente (se non ci sono visite ritorna un array vuoto) */
	private function getVisitsHistory($id) {
		/* si connette al database */
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni */
		$select = "SELECT * FROM visits_history WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto KeyValueObject da mettere nell'array */
		$visitsArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$visit = new KeyValueObject();
			$visit->patientId = $id;
			$visit->objectId = mysql_result($result,$i,"id"); // visitId
			$visit->key = mysql_result($result,$i,"name");
			$visit->value = mysql_result($result,$i,"description"); // ?
			/* aggiongo l'oggetto i-esimo all'array */
			$visitsArray[] = $visit;
		}
		return $visitsArray;
	}


}
/* #include "C:\Symbian\9.2\S60_3rd_FP1\Epoc32\include\libc\netinet\tcp.h" */
/* #include "C:\S60\devices\Nokia_N97_SDK_v1.0_2\epoc32\include\libc\netinet\tcp.h" */
?>
