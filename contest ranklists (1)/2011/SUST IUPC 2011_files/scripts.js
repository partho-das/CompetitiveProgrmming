	function echeck(str) {
	
		var at="@"
		var dot="."
		var lat=str.indexOf(at)
		var lstr=str.length
		var ldot=str.indexOf(dot)
		if (str.indexOf(at)==-1){
		   alert("Invalid E-mail ID")
		   return false
		}

		if (str.indexOf(at)==-1 || str.indexOf(at)==0 || str.indexOf(at)==lstr){
		   alert("Invalid E-mail ID")
		   return false
		}

		if (str.indexOf(dot)==-1 || str.indexOf(dot)==0 || str.indexOf(dot)==lstr){
		    alert("Invalid E-mail ID")
		    return false
		}

		 if (str.indexOf(at,(lat+1))!=-1){
		    alert("Invalid E-mail ID")
		    return false
		 }

		 if (str.substring(lat-1,lat)==dot || str.substring(lat+1,lat+2)==dot){
		    alert("Invalid E-mail ID")
		    return false
		 }

		 if (str.indexOf(dot,(lat+2))==-1){
		    alert("Invalid E-mail ID")
		    return false
		 }
		
		 if (str.indexOf(" ")!=-1){
		    alert("Invalid E-mail ID")
		    return false
		 }

 		 return true					
	}

	
	function checkPayment( form )
	{
		if(form.team_name.value=="")
		{
			alert("Enter your Team Name");
			form.team_name.focus();
			return false;
			}
			
		if(form.pin.value=="")
		{
			alert("Enter your Team PIN");
			form.pin.focus();
			return false;
			}
			
		if(form.payment_slip.value=="")
		{
			alert("Please Upload Scan copy of your Bank Draft ");
			form.payment_slip.focus();
			return false;
			}
		
		return true;
	}
	
	

	
	function checkEventRegistration( form , id)
	{
	  
		if (form.university.value == "") {
		alert( "Enter University Name!" );
		form.university.focus();
		return false ;
		}
		
		if (form.team_name.value == "") {
		alert( "Enter Team Name!" );
		form.team_name.focus();
		return false ;
		}
		
		
		if(id == 2)
		{
			
			if (form.ncscForm.value == "") {
			alert( "Please fill NCSC Form and upload it!" );
			form.ncscForm.focus();
			return false ;
			}
			
			var val = form.ncscForm.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
				if (arr[1] != "doc") 
				{
    				alert("NCSC Form must be in .doc file");
					form.ncscForm.value = "";
					return false;
  				}
			

			
			
		}
		

		if (form.name1.value == "") {
		alert( "Enter Team Leader's Name!" );
		form.name1.focus();
		return false ;
		}
	
		if (form.phone1.value == "") {
		alert( "Enter Team Leader's Phone no Please.!" );
		form.phone1.focus();
		return false ;
		}
			
		if (form.email1.value == "") {
		alert( "Enter Team Leader's Email address.!" );
		form.email1.focus();
		return false ;
		}
		
		if (echeck(form.email1.value)==false){
		form.email1.value='';
		form.email1.focus();
		return false ;
		}
		

		
		
		if(id == 1)
		{	if (form.name2.value == "") {
			alert( "Enter 2nd Member's Name!" );
			form.name2.focus();
			return false ;
			}
			
			
			
			if (form.name3.value == "") {
			alert( "Enter 3rd Member's Name!" );
			form.name3.focus();
			return false ;
			}
			
		}
		
		
		if (form.name4.value == "") {
		alert( "Enter Coach Name!" );
		form.name4.focus();
		return false ;
		}
	
		if (form.phone4.value == "") {
		alert( "Enter Coach's Phone no Please.!" );
		form.phone4.focus();
		return false ;
		}
			
		if (form.email4.value == "") {
		alert( "Enter Coach's Email address.!" );
		form.email4.focus();
		return false ;
		}
		
		if (echeck(form.email4.value)==false){
		form.email4.value='';
		form.email4.focus();
		return false ;
		}
		
		if (form.postalAddress.value == "") {
		alert( "Enter Full Postal Address Please!" );
		form.postalAddress.focus();
		return false ;
		}
		
		if(form.photo1.value != "")
		{
			var val = form.photo1.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
			
				if (arr[1] != "jpg") 
				{
    				alert("Image is not mandatory. We will publish your image in our souvenir but it must be in .jpg format. Provide jpg/jpeg image or press Submit again to continue without");
					form.photo1.value = "";
					return false;
  				}
				
		}
		
		if(form.photo2.value != "")
		{
			var val = form.photo2.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
				if (arr[1] != "jpg") 
				{
    				alert("Image is not mandatory. We will publish your image in our souvenir but it must be in .jpg format. Provide jpg/jpeg image or press Submit again to continue without");
					form.photo2.value = "";
					return false;
  				}
				
		}
		
		if(form.photo3.value != "")
		{
			var val = form.photo3.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
				if (arr[1] != "jpg") 
				{
    				alert("Image is not mandatory. We will publish your image in our souvenir but it must be in .jpg format. Provide jpg/jpeg image or press Submit again to continue without");
					form.photo3.value = "";
					return false;
  				}
				
		}
		

		if(form.photo4.value != "")
		{
			var val = form.photo4.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
				if (arr[1] != "jpg") 
				{
    				alert("Image is not mandatory. We will publish your image in our souvenir but it must be in .jpg format. Provide jpg/jpeg image or press Submit again to continue without");
					form.photo4.value = "";
					return false;
  				}
				
		}
		

		if(form.photo5.value != "")
		{
			var val = form.photo5.value;
  			var arr = val.split(".");
			var arr1 = val.split("\\");
			arr[1] = arr[1].toLowerCase();
				if (arr[1] != "jpg") 
				{
    				alert("Image is not mandatory. We will publish your image in our souvenir but it must be in .jpg format. Provide jpg/jpeg image or press Submit again to continue without");
					form.photo5.value = "";
					return false;
  				}
				
		}				
		
	
	  return true ;
	}
	
	

	
    function toggle_visibility(id) {
       var e = document.getElementById(id);
       if(e.style.display == 'block')
          e.style.display = 'none';
       else
          e.style.display = 'block';
		 //alert(id);
    }
	
	
	function showEvents()
	{
		alert("00");
	}
	
	
	
	function showEvent(id)
	{
		var e; 
				
		switch(id)
		{
		case 1:
		
		e = document.getElementById(0);  
		e.style.display = 'none';		
		e = document.getElementById(1);  
		e.style.display = 'block';
		e = document.getElementById(2);  
		e.style.display = 'none';
		e = document.getElementById(3);  
		e.style.display = 'none';
		e = document.getElementById(4);  
		e.style.display = 'none';
		e = document.getElementById(5);  
		e.style.display = 'none';
		e = document.getElementById(6);  
		e.style.display = 'none';
		break;
		
		
		case 2:
				
		e = document.getElementById(0);  
		e.style.display = 'none';
		e = document.getElementById(1);  
		e.style.display = 'none';
		e = document.getElementById(2);  
		e.style.display = 'block';
		e = document.getElementById(3);  
		e.style.display = 'none';
		e = document.getElementById(4);  
		e.style.display = 'none';
		e = document.getElementById(5);  
		e.style.display = 'none';
		e = document.getElementById(6);  
		e.style.display = 'none';
		break;
		
		case 3:
		e = document.getElementById(0);  
		e.style.display = 'none';
		e = document.getElementById(1);  
		e.style.display = 'none';
		e = document.getElementById(2);  
		e.style.display = 'none';
		e = document.getElementById(3);  
		e.style.display = 'block';
		e = document.getElementById(4);  
		e.style.display = 'none';
		e = document.getElementById(5);  
		e.style.display = 'none';
		e = document.getElementById(6);  
		e.style.display = 'none';
		break;
		
		case 4:
		e = document.getElementById(0);  
		e.style.display = 'none';
		e = document.getElementById(1);  
		e.style.display = 'none';
		e = document.getElementById(2);  
		e.style.display = 'none';
		e = document.getElementById(3);  
		e.style.display = 'none';
		e = document.getElementById(4);  
		e.style.display = 'block';
		e = document.getElementById(5);  
		e.style.display = 'none';
		e = document.getElementById(6);  
		e.style.display = 'none';
		break;
		
		case 5:
		e = document.getElementById(0);  
		e.style.display = 'none';
		e = document.getElementById(1);  
		e.style.display = 'none';
		e = document.getElementById(2);  
		e.style.display = 'none';
		e = document.getElementById(3);  
		e.style.display = 'none';
		e = document.getElementById(4);  
		e.style.display = 'none';
		e = document.getElementById(5);  
		e.style.display = 'block';
		e = document.getElementById(6);  
		e.style.display = 'none';
		break;
		
		case 6:
		e = document.getElementById(0);  
		e.style.display = 'none';
		e = document.getElementById(1);  
		e.style.display = 'none';
		e = document.getElementById(2);  
		e.style.display = 'none';
		e = document.getElementById(3);  
		e.style.display = 'none';
		e = document.getElementById(4);  
		e.style.display = 'none';
		e = document.getElementById(5);  
		e.style.display = 'none';
		e = document.getElementById(6);  
		e.style.display = 'block';
		break;				
		
		}
	}
	
	
	
	function select_all( thisid, val )
	{
	var loop;
	for( loop = 0; loop < thisid.length; loop++ )
		thisid[ loop ].checked = val;
	return true;
		//document.app.checkAll.checked = true;
	}

	
	function checkBoxLeastCheck( thisid, min )
	{
	var loop, i = 0;
	var dd=thisid.length;
	for( loop = 0; loop <= thisid.length; loop++ )
	if( thisid[ loop ].checked == true )
	   i++;
	   alert( "At least "+dd+" item(s)"+i+" n" );
	if( i < min)
	  {
	  alert( "At least "+min+" item(s)"+i+" must be selected\n"
			 +"(by a tick in Select column)\n  In order to proceed" );
	  return false;
	  }
	return true;
	}
	
	function MM_jumpMenu(targ,selObj,restore){ //v3.0
	  eval(targ+".location='"+selObj.options[selObj.selectedIndex].value+"'");
	  if (restore) selObj.selectedIndex=0;
	}
	
	
// JavaScript Document