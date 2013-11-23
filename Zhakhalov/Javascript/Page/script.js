var menu = [];
var tabs = [];

var trueName = "_monolit@ss.comZx_monolith";

var username = "";
var password= "";

$('document').ready(function()
{	
    $.ajax({
        type: "GET",
        url: "config.xml",
        dataType: "xml",
        success: parseXML
    });

    $("#user-name").keyup(function()
    {
        username = $("#user-name").val();
    });

    $("#user-password").keyup(function()
    {
        password = $("#user-password").val();
        console.trace(password);
    });
    $("#login-button").click(function()
    {
        var wrong = "";
        if((username.length < 5) || (username.length > 15))
        {
            wrong += " Username must contains 5-15 symbols!";
            $("#user-name").removeClass();
            $("#user-name").addClass("bad-text");
        }
        else if(!/^\w+$/.test(username))
        {
            $("#user-name").removeClass();
            $("#user-name").addClass("bad-text");
            wrong += " Username must contain only letters, numbers and underscores!";
        }
        else
        {
            $("#user-name").removeClass();
            $("#user-name").addClass("good-text");
        }

        if((password.length < 5) || (password.length > 15))
        {
            wrong += " Password must contains 5-15 symbols!";
            $("#user-password").removeClass();
            $("#user-password").addClass("bad-text");
        }
        else if(!/^\w+$/.test(password))
        {
            $("#user-password").removeClass();
            $("#user-password").addClass("bad-text");
            wrong += " Password must contain only letters, numbers and underscores!";
        }
        else
        {
            $("#user-password").removeClass();
            $("#user-password").addClass("good-text");
        }

        $("#user-hint").text(wrong);
    });
});

function parseTabs(xml)
{
    $(xml).find("tab-item").each(function()
    {
        var item = {title : "",link: ""};

        $(this).find("tab-title").each(function(){item.title = $(this).text();});
        $(this).find("tab-link").each(function(){item.link = $(this).text();});

        tabs.push(item);
    });
    console.trace('tabs parsed');
    createTabs();
}

function parseXML(xml)
{
    console.trace("config received");
    $("title").text($(xml).find("page-title").text());
    parseMenu(xml);
    parseTabs(xml);
}

function parseMenu(xml)
{
    $(xml).find("menu-item").each(function()
    {
        var item = {title : "", sub : new Array(), onclick : ""};


        $(this).find("menu-title").each(function(){item.title = $(this).text();});
        $(this).find("menu-onclick").each(function(){item.onclick = $(this).text();});

        $(this).find("sub-menu").each(function()
        {
            $(this).find("sub-menu-item").each(function()
            {
                var subItem = {title : "", onclick : "", onhover : ""};
                $(this).find("title").each(function(){subItem.title = $(this).text();});
                $(this).find("onclick").each(function(){subItem.onclick = $(this).text();});
                $(this).find("onhover").each(function(){subItem.onhover = $(this).text();});
                item.sub.push(subItem);
            });
        });
        menu.push(item);
    });
    console.trace('menu parsed');
    createMenu();
}

function createMenu()
{
    for(var i = 0; i < menu.length; ++i)
    {
        var text = "<li class='menu-item'>";
        text += menu[i].title;
        text += "<ul class='sub-menu'>";

        for(var j = 0; j < menu[i].sub.length; ++j)
        {
            text += "<li class='sub-menu-item'>";
            text += menu[i].sub[j].title;
            text += "</li>";
        }

        text += "</ul></li>";

        $("#menu-list").append(text);
    }

    $('.menu-item').css("width", (100 / menu.length) + "%");

    $(".menu-item").hover(
        function() {
            $(this).find('ul').stop(true,true).slideDown();
            $(this).find('ul').css("z-index",100);
            $(this).find('ul').css("width",$(".menu-item").width());
        },
        function() {
            $(this).find('ul').slideUp();
        }
    );

    $(".menu-item").mouseover(function()
    {
        $(this).siblings().removeClass("hover");
        $(this).addClass("hover");
    }).mouseout(function()
    {
        $(this).parent().children().removeClass("hover");
    });

    $(".sub-menu-item").mouseover(function()
    {
        $(this).siblings().removeClass("sub-menu-item-hover");
        $(this).addClass("sub-menu-item-hover");
		
		var index = $(this).parent().index();
		var subIndex = $(this).index();
		// eval(menu[index].sub[subIndex]onhover);  
    }).mouseout(function()
    {
        $(this).parent().children().removeClass("sub-menu-item-hover");
    }).click(function()
	{
		var index = $(this).parent().parent().index();
		var subIndex = $(this).index();
		eval(menu[index].sub[subIndex].onclick);  
	});
}

function createTabs()
{
    for(var i = 0; i < tabs.length; ++i)
        $("#tab-list").append("<li class='tab-item tab-close'>" + tabs[i].title + "</li>");

    $(".tab-item").css("width", (100 / tabs.length) + "%");

    $(".tab-item").mouseover(function()
    {
        $(this).siblings().removeClass("hover");
        $(this).addClass("hover");
    }).mouseout(function()
    {
        $(this).parent().children().removeClass("hover");
    }).click(function()
    {
        $(this).siblings().removeClass("tab-open");
        $(this).siblings().addClass("tab-close");
        $(this).removeClass("tab-close");
        $(this).addClass("tab-open");

        openTab($(this).index());
    });

    $("#tab-list").children().eq(0).addClass('tab-open');
    openTab(0);
}

function openTab(idx)
{
    $("#container").load(tabs[idx].link);
}

