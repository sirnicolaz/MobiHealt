<?php
ini_set("soap.wsdl_cache_enabled", 0);
//$wsdl = "http://".$_SERVER['HTTP_HOST']."/web/wsdl_gen/service.php?class=contactManager&wsdl";
//echo "<strong>WSDL file:</strong> ".$wsdl."<br>\n";

$client = new SoapClient("./server.wsdl", array("cache_wsdl" => 0));

echo "<hr> <strong>Result from getInfo call:</strong><br>";

$res = $client->getDio();
$contact = $res[0];
echo $contact->email;
//print_r($res);

echo "<hr><strong>Raw Soap response:</strong><br>";
echo htmlentities($client->__getLastResponse());
echo "<hr><strong>SoapFault asking for an unknown contact:</strong><br>";
$client->getContact(1);
?>