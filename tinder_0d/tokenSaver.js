function getToken()
{
  var token = document.getElementById('token').value;

  chrome.storage.sync.set({'xauth' : token}, function() {
    if(chrome.runtime.error) {
      console.log("Error saving auth.");
    }
  });
  chrome.storage.sync.get(['xauth'], function(i) {
    if(!chrome.runtime.error) {
      document.getElementById('status').textContent = i.xauth;
    }
  });
}
