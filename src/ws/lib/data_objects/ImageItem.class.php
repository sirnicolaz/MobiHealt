<?php
/**
  * oggetto che rappresenta una riga nella tabella therapy o in report
  */
class ImageItem {
	/** @var string id dell'immagine */
	public $imageId;
	
	/** @var string id del paziente */
	public $patientId;
	
	/** @var string anteprima dell'immagine in codifica base64 */
	public $base64Preview;
	
	/** @var string nome dell'immagine */
	public $name;
	
	/** @var string nota dell'immagine */
	public $imageNote;
}
?>