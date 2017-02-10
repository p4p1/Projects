<?php
	if(isset($_GET['psw'])) {
		if($_GET['psw'] == "root"){

			if(isset($_GET['user'])){
				$file = "../data/users.txt";
				$fp = fopen($file, 'a') or die('ded');
				$txt = $_GET['user'];
				echo $txt;
				fwrite($fp, $txt);
				fclose($fp);
			}
		}
	}
?>
