/* TEMPORARY DATA*/

var tabItems = [
    {name:"tab-item1", "link":"info/1.html"},
    {name:"tab-item2", "link":"info/2.html"},
    {name:"tab-item3", "link":"info/3.html"},
    {name:"tab-item4", "link":"info/4.html"},
    {name:"tab-item5", "link":"info/5.html"}];

var menuItems = [
    {name:"menu-item1",
        sub:[
            {name:"sub1-item1","link":""},
            {name:"sub1-item2","link":""},
            {name:"sub1-item3","link":""},
            {name:"sub1-item4","link":""}]},
    {name:"menu-item2",
        sub:[
            {name:"sub2-item1","link":""},
            {name:"sub2-item2","link":""},
            {name:"sub2-item3","link":""},
            {name:"sub2-item4","link":""},
            {name:"sub2-item5","link":""},
            {name:"sub2-item6","link":""}]},
    {name:"menu-iem3",
        sub:[
            {name:"sub3-item1","link":""},
            {name:"sub3-item3","link":""},
            {name:"sub3-item4","link":""}]},
    {name:"menu-item4",
        sub:[
            {name:"sub4-item1","link":""},
            {name:"sub4-item4","link":""}]
    }];

var data = [
    {text:"111111111111111111111111111111111111111111111111111<p>1111111111111111111111111111"},
    {text:"222222222222222222222222222222222222222222222222222<p>1111111111111111111111111111"},
    {text:"333333333333333333333333333333333333333333333333333<p>1111111111111111111111111111"},
    {text:"444444444444444444444444444444444444444444444444444<p>1111111111111111111111111111"},
    {text:"555555555555555555555555555555555555555555555555555<p>1111111111111111111111111111"}];


/* TEMPORARY DATA*/
$('document').ready(function()
{
    /*$.ajax({
        type: "GET",
        url: "menu.xml",
        dataType: "xml",
        success: parseTabs
    });*/

    createMenu();
    createTabs();
});

/*function parseTabs(xml)
{
    $(xml).find("tabs").each(function()
    {
        var name = $(this).find("name").text();
        tabItems.push(name);

        var link = $(this).find("link").text();
        tabLinks.push(link);
    });
    console.trace('tab parsed');
}*/

function createMenu()
{
    for(var i = 0; i < menuItems.length; ++i)
    {
        var text = "<li class='menu-item'>";
        text += menuItems[i].name;
        text += "<ul class='sub-menu'>";

        for(var j = 0; j < menuItems[i].sub.length; ++j)
        {
            text += "<li class='sub-menu-item'>";
            text += menuItems[i].sub[j].name;
            text += "</li>";
        }

        text += "</ul></li>";

        $("#menu-list").append(text);
    }

    $('.menu-item').css("width", (100 / menuItems.length) + "%");

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
    }).mouseout(function()
    {
        $(this).parent().children().removeClass("sub-menu-item-hover");
    });
}

function createTabs()
{
    for(var i = 0; i < tabItems.length; ++i)
        $("#tab-list").append("<li class='tab-item tab-close'>" + tabItems[i].name + "</li>");

    $(".tab-item").css("width", (100 / tabItems.length) + "%");

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
//   $("#container").load(tabItems[idx].link);
    $("#container").html(data[idx].text);
}
