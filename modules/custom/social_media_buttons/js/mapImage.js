//Getting the path of the first image in the content.
jQuery(document).ready(function($){
   var imgUrl = $('.content').find('img').attr('src');
   $("meta[property='og:image']").attr("content", imgUrl);    
});



