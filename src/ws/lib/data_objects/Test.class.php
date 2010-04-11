<?php
/**
  * classe di test 
  */
class Test{

	/**
	  * Hello world
	  * @return string
	  */
	public function hello() {
		return "Hello World!";
	}
	
	/**
	  * print string
	  * @param string
	  * @return string
	  */
	public function printString($in) {
		return $in;
	}	
}
/* # include "C:\Symbian\9.2\S60_3rd_FP1\Epoc32\include\libc\netinet\tcp.h" */
?>


/**
  * classe che definisce i web method esposti dal server
  
//class Server{

	/**
	  * Test
	  * @param string
	  * @return string
	  
	public function printString($in) {
		return $in;
	}
/*	
	/**
	  * Salva il file XML passato come parametro sul server
	  * @param string id del paziente
	  * @param string id dell'action
	  * @param string file XML da salvare
	  * @return boolean
	 
	public function saveData($patientId, $actionId, $data) {
		/* costruisce il percorso del file 
		$file = ".data/xml/".$patientId."_".$actionId."_data.xml";
		/* costruisce l'handler del file, scrive la stringa e chiude il file 
		$f = fopen($file, "w") or die("can't open file"); // così però il client non sa dell'errore
		fwrite($f, $data);
		fclose($f);
	}

	/**
	  * Salva l'immagine passata come parametro sul server (in tre versioni: normale, in versione mobile ed in versione anteprima)
	  * @param string id del paziente
	  * @param string l'immagine da salvere codificata in base64
	  * @return boolean
	  
	public function sendImage($patientId, $image) {
		/* si connette al database ed esegue la query di inserimento 
		$username="nurse";
		// $password="password";
		$database="live_app";
		mysql_connect("localhost",$username);
		@mysql_select_db($database) or die( "Unable to select database");
		
		$insertQuery = mysql_query("insert into images (patient_id,comment,path,name,acquisition_date) values (".$patientId.", 'Nothing','Nothing','Nothing', DATE(NOW()))");
		$getQuery = mysql_query("select * from images where patient_id='".$patientId."' order by id desc");
		$imageId = mysql_result($getQuery,0,"id");
		$query = mysql_query("update images set path='.data/img/".$imageId."' where id=".$imgName);
		/* salva l'immagine sul FS 
		$this->saveImage($image, $imageId);
	}
	
	/**
	  * Esegue la ricerca di un paziente a partire da nome, cognome, comune di residenza e codice identificativo
	  * @param string nome del paziente
	  * @param string cognome del paziente
	  * @param string comune di residenza del paziente
	  * @param string codice identificativo del paziente
	  * @return SimplePatient[]
	  
	public function	searchPatient($firstName, $lastName, $city, $patientCode) {
		/* costruisce la query di ricerca 
		$query = "SELECT * FROM patient_registry WHERE "
    			."first_name like '%".$firstName."%' AND "
    			."last_name like '%".$lastName."%' AND "
				."city like '%".$city."%' AND "
				."patient_code like '".$patientCode."'";
		
		/* si connette al database ed esegue la query di ricerca 
		$username="nurse";
		// $password="password";
		$database="live_app";
		mysql_connect("localhost",$username);
		@mysql_select_db($database) or die( "Unable to select database");
 		$result = mysql_query($query);
 		$num = mysql_numrows($result);
 		mysql_close();
		
		/* cicla sui risultati e per ogni riga trovata costruisce l'oggetto SimplePatient e lo mette nell'array 
		$patientArray = Array(); 
		for($i=0; $i<$num; $i++){
			$patient = new SimplePatient();
			$patient->patientId = mysql_result($result,$i,"id");
			$patient->name = mysql_result($result,$i,"first_name");
			$patient->lastName = mysql_result($result,$i,"last_name");
			$patient->city = mysql_result($result,$i,"city");
			$patient->patientCode = mysql_result($result,$i,"patient_code");
			/* aggiongo l'oggetto i-esimo all'array 
			$patientArray[] = $patient;
		}

		/* restituisce l'array così costruito 
		return $patientArray;			
	}
	
	/**
	  * Recupera tutte le informazioni di un paziente a partire dall'id
	  * @param string id del paziente
	  * @return Patient
	  
	public function getPatientById($id) {
		
		/* costruisce l'oggetto Patient e lo restituisce 
		$patient = new Patient();
		$patient->anagrafica = getAnagrafica($id);
		$patient->contacts = getContacts($id);
		$patient->medicalReport = getMedicalReport($id); // scheda medica
		$patient->pathologies = getPathologies($id);
		$patient->images = getImages($id);
		$patient->visitsHistory = getVisitsHistory($id); // lista delle visite effettuate
		
		return $patient;
	}
	
	/**
	  * Recupera una particolare immagine a partire dal suo id (in formato mobile)
	  * @param string id dell'immagine
	  * @return string base64image
	  
	public function getImageById($id) {
		/* recupera l'immagine identificata da $id, che è salvata in ../img/$idMobile.jpg 
		$file = "../img/".$id."Mobile.jpg";
		$imageHandler = imagecreatefromjpeg($file);
		ob_start();
		imagejpeg($imageHandler);
		$contents = ob_get_contents();
		ob_end_clean();
		/* codifica l'immagine in base64 e la ritorna 
		$encodedImage = base64_encode($contents);
		imagedestroy($image);
		
		return $encodedImage;
	}
	
	/* 
	 * FUNZIONI AUSILIARIE:
	 *	non invocabili dall'ensterno!
	 
	
	/* restituisce l'anagrafica del paziente identificato da $id 
	private function getAnagrafica($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM patient_registry WHERE id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); // sempre un solo paziente perchè id univoco
		mysql_close();

		/* costruisce l'oggetto da restituire al client e lo ritorna 
		$anagrafica = new Anagrafica();
		$anagrafica->patientId = mysql_result($result,0,"id");
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
	
	/* restituisce la lista contatti del paziente identificato da $id (se non ci sono contatti ritorna un array vuoto) 
	private function getContacts($id) {
		/* mi connetto al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupero le informazioni 
		$select = "SELECT * FROM contacts WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorro le righe ritornate dalla query e per ugnuna creo un oggetto Contact da mettere nell'array 
		$contactsArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$contact = new KeyValueObject();
			$contact->patientId = $id;
			$contact->objectId = mysql_result($result,$i,"id"); //contactId
			$contact->key = mysql_result($result,$i,"contact_name");
			$contact->value = mysql_result($result,$i,"contact_value");
			/* aggiongo l'oggetto i-esimo all'array 
			$contactsArray[] = $contact;
		}
		return $contactsArray;
	}
	
	/* restituisce la scheda medica del paziente identificato da $id 
	private function getMedicalReport($id) {
		/* crea l'oggetto per la scheda medica e recupera le informazioni in essa contenute 
		$medicalReport = new MedicalReport();
		$medicalReport->patientId = $id;
		$medicalReport->anamnesi = getAnamnesi($id);		
		$medicalReport->currentTherapies = getTherapies($id);
		$medicalReport->reports = getReports($id);
		
		return $medicalReport;
	}
	
	/* restituisce la lista delle patologie del paziente (se non ci sono patologie ritorna un array vuoto) 
	private function getPathologies($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM pathologies WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto KeyValueObject da mettere nell'array 
		$pathologiesArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$pathology = new KeyValueObject();
			$pathology->patientId = $id;
			$pathology->objectId = mysql_result($result,$i,"id"); // pathologyId
			$pathology->key = mysql_result($result,$i,"pathology_name");
			$pathology->value = mysql_result($result,$i,"pathology_description");
			/* aggiongo l'oggetto i-esimo all'array 
			$pathologiesArray[] = $pathology;
		}
		return $pathologiesArray;
	}
	
	/* restituisce la lista delle immagini associate al paziente identificato da $id 
	private function getImages($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");
		
		/* recupera le informazioni 
		$select = "SELECT * FROM images WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto ImageItem da mettere nell'array 
		/* se il paziente non ha immagini associate, restituisce un array vuoto 
		$imagesArray = Array();
		
		for($i=0; $i<$num; $i++){
			$image = new ImageItem();
			$image->imageId = mysql_result($result,$i,"id");
			$image->patientId = $id;
			$image->base64Preview = getImagePreview($image->imageId); // ritorna l'anteprima dell'immagine in base64
			$image->name = mysql_result($result,$i,"name");
			$image->imageNote = mysql_result($result,$i,"comment");
			/* aggiongo l'oggetto i-esimo all'array 
			$imagesArray[] = $image;
		}
		return $imagesArray;
	}
	
	/* restituisce la preview dell'immagine identificata da $image_id in base64 
	private function getImagePreview($image_id)
	{
		/* recupera l'anteprima dell'immagine, salvata nel server come in ../img/ con nome $image_idPreview.jpg 
		$file = "../img/".$image_id."Preview.jpg";
		$imageHandler = imagecreatefromjpeg($file);
		ob_start();
		imagejpeg($imageHandler);
		$contents =  ob_get_contents();
		ob_end_clean();
		/* codifica l'immagine in base64 e la ritorna 
		$base64image = base64_encode($contents);
		imagedestroy($imageHandler);
		
		return $base64image;
	}
	
	/* restituisce la lista delle visite mediche effettuate dal paziente (se non ci sono visite ritorna un array vuoto) 
	private function getVisitsHistory($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM visit_history WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto KeyValueObject da mettere nell'array 
		$visitsArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$visit = new KeyValueObject();
			$visit->patientId = $id;
			$visit->objectId = mysql_result($result,$i,"id"); // visitId
			$visit->key = mysql_result($result,$i,"visit_name");
			$visit->value = mysql_result($result,$i,"visit_description"); // ?
			/* aggiongo l'oggetto i-esimo all'array 
			$visitsArray[] = $visit;
		}
		return $visitsArray;
	}
	
	/* ritorna la storia clinica del paziente identificato da $id 
	private function getAnamnesi($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM history WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto Anamnesi da mettere nell'array 
		$anamnesiArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$anamnesi = new Anamnesi();
			$anamnesi->anamnesiId = mysql_result($result,$i,"id");
			$anamnesi->patientId = $id;
			$anamnesi->title = mysql_result($result,$i,"title");
			$anamnesi->text = mysql_result($result,$i,"text");
			$dateObj = strtotime(mysql_result($result,$i,"date"));
			$anamnesi->date = date("d", $dateObj)."/".date("m", $dateObj)."/".date("Y", $dateObj);
			/* aggiongo l'oggetto i-esimo all'array 
			$anamnesiArray[] = $anamnesi;
		}
		return $anamnesiArray;
	}
	
	/* ritorna la lista delle terapie a cui è sottoposto attualmente il paziente 
	private function getTherapies($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM therapy WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto Therapy da mettere nell'array 
		$therapiesArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$therapy = new TherapyReport();
			$therapy->objectId = mysql_result($result,$i,"id");
			$therapy->patientId = $id;
			$therapy->title = mysql_result($result,$i,"title");
			$therapy->text = mysql_result($result,$i,"text");
			/* aggiongo l'oggetto i-esimo all'array 
			$therapiesArray[] = $therapy;
		}
		return $therapiesArray;
	}
	
	/* ritorna la lista di report del paziente identificato da $id 
	private function getReports($id) {
		/* si connette al database 
		mysql_connect("localhost", "nurse");
	  	@mysql_select_db("live_app") or die( "Unable to select database");

		/* recupera le informazioni 
		$select = "SELECT * FROM report WHERE patient_id = ". $id;
		$result = mysql_query($select);
		$num = mysql_numrows($result); 
		mysql_close();
		
		/* scorre le righe ritornate dalla query e per ugnuna creo un oggetto Report da mettere nell'array 
		$reportsArray = Array();
		
		for($i=0; $i<$num; $i++){			
			$report = new TherapyReport();
			$report->objectId = mysql_result($result,$i,"id");
			$report->patientId = $id;
			$report->title = mysql_result($result,$i,"title");
			$report->text = mysql_result($result,$i,"text");
			/* aggiongo l'oggetto i-esimo all'array 
			$reportsArray[] = $report;
		}
		return $reportsArray;
	}
	
	/* salva l'immagine sul FS del server 
	private function saveImage($image, $imageId) {
		$newFile="../img/".$imageId.".jpg"; // versione normale
		$newFileScaled="../img/".$imageId."Scaled.jpg"; // versione scalata
		$newFileMobile="../img/".$imageId."Mobile.jpg"; // versione mobile
		
		/* image dimension 
		$scaled_width=320;
		$scaled_height=240;
		$mobile_width=640;
		$mobile_height=480;
		
		/* salva la versione normale 
		$decodedImage=base64_decode($image);
		$restoredImage=imagecreatefromstring($decodedImage);
		imagejpeg($restoredImage,$newFile,100);

		/* operazioni di scaling sulle dimensioni per salvare la versione scaled e salvataggio 
		list($image_width, $image_height) = getimagesize($newFile);
		if($image_width > $scaled_width || $image_height > $scaled_height){
			$proportions = $image_width/$image_height;
			if($image_width>$image_height)
			{
				$new_width = $scaled_width;
				$new_height = round($scaled_width/$proportions);
			}		
			else
			{
				$new_height = $scaled_height;
				$new_width = round($scaled_height*$proportions);
			}		
						    
			$new_image = imagecreatetruecolor($new_width , $new_height);
			imagecopyresampled($new_image, $restoredImage, 0, 0, 0, 0, $new_width, $new_height, $image_width, $image_height);
			imagejpeg($new_image,$newFileScaled,60);
			imagedestroy($new_image);
		}
		else
		{
			imagejpeg($restoredImage,$newFileScaled,60);
		}
		
		/* operazioni di scaling sulle dimensioni per salvare la versione mobile e salvataggio     
		if($image_width > $mobile_width || $image_height > $mobile_height){
			$proportions = $image_width/$image_height;			    
			if($image_width>$image_height)
			{
				$new_width = $mobile_width;
				$new_height = round($mobile_width/$proportions);
			}		
			else
			{
				$new_height = $mobile_height;
				$new_width = round($mobile_height*$proportions);
			}		
						    
			$new_image = imagecreatetruecolor($new_width , $new_height);
			imagecopyresampled($new_image, $restoredImage, 0, 0, 0, 0, $new_width, $new_height, $image_width, $image_height);
			imagejpeg($new_image,$newFileMobile,50);
			imagedestroy($new_image);
		}
		else
		{
			imagejpeg($restoredImage,$newFileMobile,50);
		}
		
	}
	*/
/*}

?>*/