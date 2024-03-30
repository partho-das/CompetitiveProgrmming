$(document).ready(function(){
	var teamNameok = false;
	var myVar = true;
	var boxes = $(".input_s1_normal");
	var myForm = $("#chkForm"),  teamName = $("#team_name"), teamNameInfo = $("#teamNameInfo"), university = $("#university");
	
	//give some effect on focus
	boxes.focus(function(){
		$(this).addClass("input_s1_focus");
	});
	//reset on blur
	boxes.blur(function(){
		$(this).removeClass("input_s1_focus");
	});
	
	//Form Validation

		
	//send ajax request to check teamName
	teamName.blur(function(){
		$.ajax({
			type: "POST",
			data: "teamName="+$(this).attr("value"),
			url: "check.php",
			beforeSend: function(){
				teamNameInfo.html("Checking teamName...");
			},
			success: function(data){
				if(data == "invalid")
				{
					
					teamNameok = false;
					myVar = false;
					teamNameInfo.html("Must contain more than two characters begin with an Alphabet.");
					//document.chkForm.team_name.value='';

					teamName.focus();
					teamName.select();
				}
				else if(data != "0")
				{
					teamNameok = false;
					myVar = false;
					teamNameInfo.html(''+ document.chkForm.team_name.value +' already Exists. Please try with another Team Name');
					teamName.focus();
					teamName.select();
				}
				else
				{
					teamNameok = true;
					myVar = true;
					teamNameInfo.html("teamName OK");
				}
			}
		});
	});
	
		
	
		
	
});