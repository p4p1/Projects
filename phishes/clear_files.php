<?php

if( ($remote_addr = $_SERVER['REMOTE_ADDR']) == '') {
    $remote_addr = "REMOTE_ADDR_UNKNOWN";
}

if ($_POST['clearFB']){
  $flog = fopen("../web.log", 'a') or die("can't open logs");
  $logtext = date("Y-m-d") . " | " . date("h:i:sa") . " | " . $remote_addr . " | Cleared facebook.\n";

  $myTextFileHandler = @fopen("facebook/stolen.txt","w") or die("can't open file");
  fwrite($myTextFileHandler, "");
  header("Location:admin.html");

  fwrite($flog, $logtext);
  fclose($flog);
} else if ($_POST['clearTW']) {
  $flog = fopen("../web.log", 'a') or die("can't open logs");
  $logtext = date("Y-m-d") ." | " . date("h:i:sa") . " | " . $remote_addr . " | Cleared facebook.\n";

  $myTextFileHandler = @fopen("twitter/stolen.txt","w") or die("can't open file");
  fwrite($myTextFileHandler, "");
  header("Location:admin.html");

  fwrite($flog, $logtext);
  fclose($flog);
} else if($_POST['clearVC']) {
  $flog = fopen("../web.log", 'a') or die("can't open logs");
  $logtext = date("Y-m-d") ." | " . date("h:i:sa") . " | " . $remote_addr . " | Cleared viescolaire.\n";

  $myTextFileHandler = @fopen("viescolaire/stolen.txt","w") or die("can't open file");
  fwrite($myTextFileHandler, "");
  header("Location:admin.html");

  fwrite($flog, $logtext);
  fclose($flog);
} else {
  echo "ERROR";
}

 ?>
