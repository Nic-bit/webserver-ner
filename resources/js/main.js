(function(a){a("#mobile-menu").meanmenu({meanMenuContainer:".mobile-menu",meanScreenWidth:"992"});a(".portfolio-area").imagesLoaded(function(){var b=a(".grid").isotope({itemSelector:".grid-item",percentPosition:true,masonry:{columnWidth:1}});a(".portfolio-menu").on("click","button",function(){var c=a(this).attr("data-filter");b.isotope({filter:c})});a(".portfolio-menu button").on("click",function(c){a(this).siblings(".active").removeClass("active");a(this).addClass("active");c.preventDefault()})});a(".portfolio-area").imagesLoaded(function(){var b=a(".grid2").isotope({itemSelector:".grid-item",percentPosition:true,layoutMode:"fitRows",masonry:{columnWidth:1}});a(".portfolio-menu").on("click","button",function(){var c=a(this).attr("data-filter");b.isotope({filter:c})});a(".portfolio-menu button").on("click",function(c){a(this).siblings(".active").removeClass("active");a(this).addClass("active");c.preventDefault()})});a(".image-link").magnificPopup({type:"image",gallery:{enabled:true}});a(".popup-video").magnificPopup({type:"iframe"});a.scrollUp({scrollName:"scrollUp",topDistance:"300",topSpeed:300,animation:"fade",animationInSpeed:200,animationOutSpeed:200,scrollText:'<i class="fa fa-angle-up"></i>',activeOverlay:false,});new WOW().init();a(".brand-active").owlCarousel({loop:true,nav:false,autoplay:true,dots:false,responsive:{0:{items:1},576:{items:2},768:{items:3},992:{items:4},1200:{items:4}}})})(jQuery);