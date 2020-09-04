function setAutoLiker()
{
  chrome.storage.sync.get(['autoliker'], function(i) {
    if(!chrome.runtime.error) {
      chrome.storage.sync.set({'autoliker' : !i.autoliker}, function() {
        if(chrome.runtime.error) {
          console.log("Error setting boolean.");
        }
      });
    }
  });
}
