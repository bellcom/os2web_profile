//Making sure that users are getting a popup windows when pressing sharing buttons.
jQuery(document).ready(function($){
$('.social_media_button_link').click(function(){
   var whatToLink = $(this).attr('href'); 
   window.open(whatToLink, 'newwindow', 'width=600 height=300');
   return false;
});
});