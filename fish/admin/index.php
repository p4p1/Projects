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
		<h1>Admin page for fish</h1>

		<div class="div_class" id="redirect_div_id">
			<h2 class="h2_class" id="redirect_header_id">redirect to page:</h2>
			<form action="" method="POST" id="redirect_form_id">
				<input type="text" name="red_url" placeholder="url here" id="redirect_placeholder_id" class="input_redirect_class"/>
				<input type="submit" name="submit" value="save" id="redirect_button_id" class="input_redirect_class"/>
			</form>
		</div>
		<div class="div_class" id="allowed_users_div_id">
			<h2 class="h2_class" id="allowed_users_header_id">allowed users:</h2>
			<ul class="allowed_users_list_class" id="allowed_users_list_id">
		<?php $file = "../data/users.txt";
					$fip = fopen($file, 'r') or die("can't open file");
					$i = 0;
			    if($fip) {
      			while(!feof($fip)) {
      	  		$line = fgets($fip);
							if(strlen($line) > 1){
								$i += 1;
								echo '<li class="allowed_user_list_ellement_class"'. 'id="allowed_user_list_ellement_no'. $i .'">' . $line . '</li>';
							}
			      }
						fclose($fip);
    			} else {
						echo '<li class="allowed_user_list_ellement_class" id="allowed_user_list_error">Error reading the file!</li>';
					} ?>
			</ul>
		</div>
		<div class="div_class" id="add_new_user_div">
			<h2 class="h2_class" id="add_new_user_header_id">add new user:</h2>
			<input type="submit" onclick="var user = prompt('user ip:'); document.location.href='../fish_logic/add_new_user.php?psw=root&user={}'.format(user)">
		</div>
	<hr />
	<code class="code_class" id="sample_html_code">
			&ltform action="login.php" method="POST"><br />
&nbsp				&ltlabel>Nom d'utilisateur:&lt/label>&ltbr /><br />
&nbsp				&ltinput type="username" name="Email" id="Email">&ltbr /><br />
&nbsp				&ltlabel>Mots de passe:&lt/label>&ltbr /><br />
&nbsp				&ltinput type="password" name="Passwd" id="Passwd"><br />
<br />
&nbsp				&ltinput type="submit" name="signIn" id="signIn" value="Mise a jour"><br />
			&lt/form><br />
		</code>
	</body>
</html>
