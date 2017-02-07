<?php
	function login() {
		$ip = $_SERVER['REMOTE_ADDR'] . "\n";
		$file = "../data/users.txt";
		$fip = fopen($file, 'r') or die("can't open file");
	
		if($fip) {
			while(!feof($fip)) {
				$line = fgets($fip);
				if($line == $ip) {
					goto ip_valid;
				}
			}
			header('Location: http://www.google.com');
			ip_valid:
			fclose($fip);
		}
	}

	if($_SERVER['REQUEST_METHOD'] === 'POST') {
		if(strlen($_POST['red_url']) != 0){
			$file = fopen("../fish_logic/redirect.js", 'w') or die("can't open file");
			$str = "document.location.href='" . $_POST['red_url'] . "';";
			fwrite($file, $str);
			fclose($file);
		}
	} else {
		login();
	}
?>

<!DOCTYPE html>
<html>
	<head>
		<title>Admin - fish</title>
	</head>
	<body>
		<h1>Admin page fishes.net</h1>

		<dir>
			<h2>redirect to page:</h2>
			<form action="" method="POST">
				<input type="text" name="red_url" placeholder="hy"/>
				<input type="submit" name="submit" value="save" />
			</form>
		</dir>
	<hr />
	<code>
			&ltform action="login.php" method="POST"><br />
&nbsp				&ltlabel>Nom d'utilisateur:&lt/label>&ltbr /><br />
&nbsp				&ltinput type="username" name="Email" id="Email">&ltbr /><br />
&nbsp				&ltlabel>Mots de passe:&lt/label>&ltbr /><br />
&nbsp				&ltinput type="password" name="Passwd" id="Passwd"><br />
<br />
&nbsp				&ltinput type="submit" name="signIn" id="signIn" value="Mise a jour"><br />
<br />
			&lt/form><br />
		</code>
	</body>
</html>
