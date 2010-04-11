<?php
/**
  * oggetto che rappresenta una paziente nel sistema
  */
class Patient {
	/** @var string id del paziente */
	public $patientId;
	/** @var Anagrafica anagrafica */
	public $anagrafica;
	/** @var KeyValueObject[] contatti */
	public $contacts;
	/** @var MedicalReport scheda medica */
	public $medicalReport;
	/** @var KeyValueObject[] lista delle patologie */
	public $pathologies;	
	/** @var ImageItem[] lista delle immagini */
	public $images;
	/** @var KeyValueObject[] lista delle visite effettuate */
	public $visitHistory;	
}
?>