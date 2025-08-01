(function($){
	
	$.confirm = function(params){
		
		if($('#confirmOverlay').length){
			// A confirm is already shown on the page:
			return false;
		}
		
		var buttonHTML = '';
		$.each(params.buttons,function(name,obj){
			
			// Generating the markup for the buttons:
			
			buttonHTML += '<a href="#" class="button '+obj['class']+'">'+name+'<span></span></a>';
			
			if(!obj.action){
				obj.action = function(){};
			}
		});
		
		var markup = [
			'<div class="w3-maskdiv">',
			'<div class="w3-largecarm w3-confirm">',
			'<h1>',params.title,'</h1>',
			'<p>',params.message,'</p>',
			//'<div id="confirmButtons">',
			buttonHTML,
			'</div></div>'
		].join('');
		
		$(markup).hide().appendTo('body').fadeIn();
		
		var buttons = $('.w3-confirm .button'),
			i = 0;

		$.each(params.buttons,function(name,obj){
			buttons.eq(i++).click(function(){
				
				// Calling the action attribute when a
				// click occurs, and hiding the confirm.
				
				obj.action();
				$.confirm.hide();
				return false;
			});
		});
	}
   
	$.confirm.hide = function(){
		$('.w3-maskdiv').fadeOut(function(){
			$(this).remove();
		});
	}
	
})(jQuery);