<?php
/**
  * oggetto che rappresenta una riga nella tabella history (cioè un evento nella storia clinica del paziente)
  */
class Anamnesi {
	/** @var string id della riga */
	public $anamnesiId;
	
	/** @var string id del paziente */
	public $patientId;
	
	/** @var string titolo dell'anamnesi */
	public $title;
	
	/** @var string testo dell'anamnesi */
	public $text;
	
	/** @var string data dell'anamnesi */
	public $date;
}
?>