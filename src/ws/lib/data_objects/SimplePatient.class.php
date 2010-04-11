<?php
/**
  * oggetto che rappresenta un paziente nella lista pazienti ritornata dalla ricerca
  */
class SimplePatient{
	/** @var string id del paziente a cui si riferisce */
	public $patientId;
	
	/** @var string nome del paziente */
	public $name;
	
	/** @var string cognome del paziente */
	public $lastName;
	
	/** @var string comune di residenza del paziente */
	public $city;
	
	/** @var string codice identificativo del paziente */
	public $patientCode;
}
?>