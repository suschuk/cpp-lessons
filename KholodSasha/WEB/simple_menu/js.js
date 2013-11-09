$(document).ready(function(){
  $('#menu li').hover(function () {
     clearTimeout($.data(this,'timer'));
     $('ul',this).stop(true,true).slideDown(200);
  }, function () {
    $.data(this,'timer', setTimeout($.proxy(function() {
      $('ul',this).stop(true,true).slideUp(200);
    }, this), 100));
  });
});

$(document).ready(function(){
	$('#menu li li a').on('click',function(){
		alert(this.text);
	});
});
