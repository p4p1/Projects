setInterval(function() {
  var element = document.getElementsByClassName("Bdrs(8px) Bgz(cv) Bgp(c) Ov(h) StretchedBox Ir(p) Cnt($blank)::a StretchedBox::a Bg($inherit)::a Scale(1.3)::a Scale(1.2)::a--s Blur(12px)::a");
  var url = "";

  for (i = 0; i < element.length; i++) {
    url = element[i].style["background-image"];
    element[i].style["background-image"] = url.replace("84x106", "640x800");
    element[i].className = "Bdrs(8px) Bgz(cv) Bgp(c) Ov(h) StretchedBox Ir(p) Cnt($blank)::a StretchedBox::a Bg($inherit)::a Scale(1.3)::a Scale(1.2)::a--s";
  }
}, 500);
