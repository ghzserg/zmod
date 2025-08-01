$(document).ready(function (){
	//$(".w3-maskdiv").show();
	//$(".w3-newupdate").show();
	printerInfo();
	//switchSet("#Nozzle_switch","/nozzlePreheat");
  	//switchSet("#Bed_switch","/bedPreheat");
	$(".w3-theme-l4").bind("click",function(){
	$(".w3-maskdiv").show();
	$(".w3-largecarm").show();
	//alert();
	//$(".w3-maskdiv").height($(document).height());
	})
	$(".close").bind("click",function(){
	$(".w3-maskdiv").hide();
	$(".w3-largecarm").hide();
		})
});
function printerInfo(){
	$.ajax({
		url:"/getHomeMessage",
		type:"post",
		data:"",
		dataType:"json",
		contentType:"application/x-www-form-urlencoded;charset=utf-8",
		beforeSend: function(){
            },
        success: function(data){
			if (data.hasOwnProperty("ErrorCode")) {
               if (data.ErrorCode == 200) {
				   //getSwitch(data.PreheatNozzle,"#Nozzle_switch");
				   //getSwitch(data.PreheatBed,"#Bed_switch");
				   $(".fa-pencil").text(data.PrinterMicrons);
				   $(".fa-home").text(data.PrinterBedMessage);
				   $(".fa-birthday-cake").text(data.PrinterNozzleMessage);
				   $(".fa-print").text(data.FirwareVersion);
				   $(".fa-counter").text(data.UsageCounter+" hours");
				   $(".fa-serial").text(data.SerialNumber);
				   $(".fa-add1").text(data.ExtruderType);
				   $(".fa-add2").text(data.PrinterName);
				   $(".fa-add3").text(data.RegistrationCode);
				   $(".fa-add4").text(data.PolarSerialNo);
				   var filtype=data.FilamentType;
				   $(".w3-tag").eq(filtype-1).addClass("w3-Materialcur").removeClass("w3-teal");
				   $("#NozzleTemp").text(data.NozzleTemp);
				   $("#NozzleTempTarget").text(data.NozzleTempTarget);
				   $("#BedTempTarget").text(data.BedTempTarget);
				   $("#BedTemp").text(data.BedTemp);
				   $("#PrinterFiles").text(data.PrinterFiles);
				   //$("#PrinterFiles").text(data.PrinterFiles);
				   $(".w3-green").css("width",data.PrintererAvailabelStorage + "%");
				   $(".w3-green span").text(data.PrintererAvailabelStorage);
				   $("#PrintingPres").css("width",data.PrintingProgress + "%");
				   $("#PrintingPres span").text(data.PrintingProgress + "%")
				   var ptStatus=data.PrinterStatus;
				   ptStatus=ptStatus.slice(0,1).toUpperCase()+ptStatus.slice(1);
				   $(".status").text(ptStatus);
				   if(ptStatus=="Idle"||ptStatus=="Change_filament"||ptStatus=="Leveling"||ptStatus=="Calibration"||ptStatus=="DoorOpen"){
					   $(".w3-printed,.w3-leftTime").hide();
				       $(".w3-Ptstatus").css("text-align","left");
					   $("#PrintingPres").css("width","0%");
					   $("#PrintingPres span").text("0%");
					   }
				   else {
					   $(".w3-printed,.w3-leftTime").show();
					   $(".w3-Ptstatus").css("text-align","right");
					   $("#PrintingFile").text(data.PrintingFileName);
				       $("#FilePic").attr("src",data.PrintingFilePic);
					   $("#FilePic").attr("alt",data.PrintingFileName);
					   }
				   $("#Camera").attr("src",data.PrinterCamera);
				   $("#Camera_large").attr("src",data.PrinterCamera);
				   var leftTime=secondTo(data.RemainTime);
				   $(".time").text(leftTime);
				   }
			}
			},
		error:function(er,es,e) {
				alert("Server connection failed");
				
            },
		})
	
	}
function secondTo(leftTime){
	var h=Math.floor(leftTime/3600);
	var m=Math.floor(leftTime/60%60);
	//h=lessTen(h);
	//m=lessTen(m);
	if(h>=1){
		leftTime=h+'hr '+m+'min';
		}
	else {
		leftTime="00hr "+m+'min'; 
		}
	return leftTime;
	}
function lessTen(num){
	if(num<10){
		return num="0"+num;
	   }
	else{
		return num;
		}
	}
/*switch*/
function switchSet(checkbox,urlpar){
	var check=$(checkbox).is(":checked");
	if(!check){
		var on="on";
		}
	  else{
		var on="on";
		  }
	$.ajax({
            url: urlpar,
            type: "post",
            data: JSON.stringify({
                value:on,
            }),
            dataType:"json",
            contentType:"application/x-www-form-urlencoded;charset=utf-8",

            beforeSend: function(){
            },
            success: function(data){
			   if (data.hasOwnProperty("ErrorCode")) {
				 if (data.ErrorCode == 200) {
			     }
                 else if (data.ErrorCode == 400) {
					alert(data.Message);//错误信息
			     }
				}
			},
			error:function(er,es,e) {
				alert("Server connection failed");
            },
        });
	   }


window.onload=function(){
	$("#ifrmid").contents().find("#home").addClass("w3-teal").removeClass("w3-white");
	}

window.setInterval(function () {
        printerInfo();
    }, 5000);



