<?php

if( ($remote_addr = $_SERVER['REMOTE_ADDR']) == '') {
    $remote_addr = "REMOTE_ADDR_UNKNOWN";
}

if($_POST['changedirect']){

  $fbredirect = "facebook/javascript.js";
  $twredirect = "twitter/javascript.js";
  $vcredirect = "viescolaire/javascript.js";

  $ftw = fopen($twredirect, 'w') or die("can't open file1");
  $ffb = fopen($fbredirect, 'w') or die("can't open file2");
  $fvc = fopen($vcredirect, 'w') or die("can't open file3");

  $flog = fopen("../web.log", 'a') or die("can't open logs");

  $texttw = "var redirect = '" . $_POST['redirectTW'] . "';window.location.replace(redirect);";
  $textbf = "var redirect = '" . $_POST['redirectFB'] . "';window.location.replace(redirect);";
  $textvc = "var redirect = '" . $_POST['redirectVC'] . "';window.location.replace(redirect);";

  $logtext1 = date("Y-m-d") ." | " . date("h:i:sa") . " | " . $remote_addr . " | Changed url facebook to: " . $_POST['redirectFB'] . "\n";
  $logtext2 = date("Y-m-d") ." | " . date("h:i:sa") . " | " . $remote_addr . " | Changed url twitter to: " . $_POST['redirectTW'] . "\n";
  $logtext3 = date("Y-m-d") . " | " . date("h:i:sa") . " | " . $remote_addr . " | Changed url viescolaire to: " . $_POST['redirectVC'] . "\n";

  fwrite($ftw, $texttw);
  fwrite($ffb, $textbf);
  fwrite($fvc, $textvc);
  fwrite($flog, $logtext1);
  fwrite($flog, $logtext2);
  fwrite($flog, $logtext3);

  fclose($ftw);
  fclose($ffb);
  fclose($fvc);
  fclose($flog);

  header("Location:admin.html");

} else {
  echo "ERROR";
}

?>
