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
	$('div p').hide();
	$('#menu li li a').on('click',function(){
		var target = $("#" + this.name).eq(0);
		target.slideToggle('slow');
	});
});
$(function(){
		$("#slides").slides({
			responsive: true
		});
});