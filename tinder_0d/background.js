function requesting(token)
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var data = JSON.parse(this.responseText);
      console.log(data);
    }
  };
  xhttp.open("GET", "https://api.gotinder.com/user/recs", true);
  xhttp.setRequestHeader("x-auth-token", token);
  xhttp.setRequestHeader("accept", "application/json");
  xhttp.setRequestHeader("Access-Control-Allow-Origin", "*");
  xhttp.send();
}

setInterval(function() {
  chrome.storage.sync.get(['autoliker', 'xauth'], function(i) {
    if(!chrome.runtime.error) {
      if (i.autoliker) {
        requesting(i.xauth);
      }
    }
  });
}, 500);
