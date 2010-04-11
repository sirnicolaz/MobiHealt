<?php
/**
  * oggetto che rappresenta una riga nella tabella therapy o in report
  */
class TherapyReport {
	/** @var string id della riga */
	public $objectId;
	
	/** @var string id del paziente */
	public $patientId;
	
	/** @var string titolo  della terapia/report */
	public $title;
	
	/** @var string testo della terapia/report */
	public $text;
}
?>