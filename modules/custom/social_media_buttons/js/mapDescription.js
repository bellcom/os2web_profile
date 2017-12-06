//Getting the first part of content.
jQuery(document).ready(function($){
   var description = $('p').text().substring(0,305);
   $("meta[property='og:description']").attr("content", description);
   //console.log(description);
});


