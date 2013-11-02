$(document).ready(
	function () {
	
	
	$("#menu_warper ul li ul").addClass("m");
	
	$("#menu_warper").children().children().attr(
	{
		id:function (index, oldValue)
		{
			return "MI-" + index;
		}
	}
	);
	
	
	
	$("#menu_warper").children().children().addClass("MI");
	
	$(".MI > ul").hide();
	
	$("#menu_warper ul li ul").addClass("subMI");
	
	$('ul li ul li ul').removeClass().addClass('deepMI').hide().parent().addClass("hasSubMenu")
	;
	
	$('.deepMI').parent().mouseenter( sh1 ).mouseleave( hd1 );
	
	function test()
	{
		$(this).addClass('bgMenu')
	}
		function test2()
	{
		$(this).removeClass('bgMenu')
	}
	
	function hd(){
	$(this).children('ul').stop(true,true).fadeTo('fast', 1.0).slideUp('fast');
	$(this).removeClass('bgMenu');
	}
	
	function sh(){
	$(this).children('ul').stop(true,true).fadeTo('fast', 1.0).slideDown('fast');
	$(this).addClass('bgMenu');
	}
	
	function hd1(){
	$(this).find('ul').stop(true,true).show().slideUp('fast');
	}
	
	function sh1(){
	$(this).find('ul').stop(true,true).hide().slideDown('fast');
	}
	

	
	$("#menu").children().mouseenter( sh ).mouseleave( hd );
	
	$("a").parent().mouseenter(function()
	{
		$(this).children('a').addClass('fHover');
	});
	
	$("a").parent().mouseleave(function ()
	{
		$(this).children('a').removeClass('fHover');
	})
	



	
	
	});