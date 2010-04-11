<?php
/**
  * oggetto che rappresenta una scheda medica di un paziente
  */
class MedicalReport {
	/** @var string id del paziente */
	public $patientId;
	
	/** @var Anamnesi[] storia clinica del paziente */
	public $anamnesi;
	
	/** @var TherapyReport[] terapie a cui è sottoposto il paziente */
	public $currentTherapies;
	
	/** @var TherapyReport[] report del paziente */
	public $reports;
}
?>