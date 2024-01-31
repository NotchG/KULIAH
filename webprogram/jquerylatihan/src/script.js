// JQuery selector: Select elemen di dalam htmlnya

//Cek if dokumen udah ready

const images = ["../image1.avif", "../image2.jpeg", "../image3.jpg"];
var max = 2;
var index = 0;

$(function() {
    // Selector
    // Class pake titik
    // ID pake pagar
    /*$("ul").click(function() {
        $(this).hide();
    });*/

    // Event
    // event hover, click, double click, keypress
    /*$("#input").hover(function () {
        $(this).hide();
    })*/

    // Jquery Effect
    // Slide, fade, hide, show, animate
    /*$("#hello").click(function () {
        $(".container").animate({
            
        });
    });*/

    //Images
    /*var helloValue = $(".hello").val;
    alert(helloValue);*/
    $("#prevButton").click(function () {
        index--;
        if (index < 0) {
            index = max;
        }

        $(".imageContainer").attr({
            "src": images[index],
        });
    });

    $("#nextButton").click(function() {
        index++;
        if (index > max) {
            index = 0;
        }

        $(".imageContainer").attr({
            "src": images[index],
        });
    });

    $("")


});