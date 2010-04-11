<?php
/**
  * oggetto che rappresenta l'anagrafica di un paziente
  */
class Anagrafica {
	/** @var string id del paziente */
	public $patientId;
	
	/** @var string codice paziente */
	public $patientCode;
	
	/** @var string nome del paziente */
	public $name;
	
	/** @var string cognome del paziente */
	public $lastName;	
	
	/** @var string indirizzo del paziente*/
	public $address;
	
	/** @var string cap della città del paziente*/
	public $cap;
	
	/** @var string città del paziente */
	public $city;
	
	/** @var string provincia del paziente */
	public $province;
	
	/** @var string data di nascita del paziente */
	public $birthDate;
	
	/** @var string medico di base del paziente */
	public $GP;

	/** @var string codice fiscale del paziente */
	public $CF;
	
	/** @var string professione del paziente */
	public $profession;
	
	/** @var string luogo di nascita del paziente */
	public $birthLocation;
	
	/** @var string stato coniugale del paziente */
	public $marital;	
}
?>