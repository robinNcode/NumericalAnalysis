var videobaseurl = "https://www.tutorialspoint.com/market/subscription";
$(document).ready(function(){
	$('.pop-modal').hide();
	$(document).on('click', '.popdiv .close, .report-btn-close, .suggestion-btn-close', function () {
		$(".popdiv .pop-content").html('');
		$('.popdiv .msg').html('');
		$('.pop-modal').hide();
	});
});
function printPage() { window.print(); }
function notesClose(){
	$("#text_notes_div").hide();
	$("#div-right-menu").show();
}
function submit_text_notes(){
	$(".wrap_loader").show();  
	var vu = $("#vu").val();
	var title = $(document).find("title").text();
	var text_notes = $("#text_notes").val();
	var url = $(location).attr("href");
	$.ajax({
		type: "GET",
		dataType: "json",
		url: videobaseurl+"/ajaxTextAddNotes.php",
		data: {"vu":vu, "text_notes":text_notes, "url":url,"title":title},
		success: function(data){
			$(".wrap_loader").hide();
			$('.notes_msg').html(data.msg);
			setTimeout(function () {
				$('.notes_msg').html('');
			}, 3000);
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
function add_notes(){
	var vu = $("#vu").val();
	var url = $(location).attr("href");
	$.ajax({
		type: "GET",
		dataType: "json",
		url: videobaseurl+"/ajaxTextGetNotes.php",
		data: {"vu":vu, "url":url},
		success: function(data){
		    $(".wrap_loader").hide();
		    $("#text_notes").val(data.text_notes);
		    $("#text_notes_div").show();
		    $("#div-right-menu").hide();
		    var elem = $("#buy_sub_div");
			if(elem){
				elem.hide();	
			}
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
function report_error_popup(){
	var content = "report_error_popup";
	var title = document.title;
	$(".wrap_loader").show();
	$.ajax({
		type: "GET",
		url: videobaseurl+"/ajaxTextGetContent.php",
		data: {"content":content, "title":title},
		success: function(data){
		   $(".wrap_loader").hide();
		   $(".popdiv .pop-content").html(data);
		   $('.pop-modal').show();
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
function suggestion_popup(){
	var content = "suggestion_popup";
	var title = document.title;
	$(".wrap_loader").show();
	$.ajax({
		type: "GET",
		url: videobaseurl+"/ajaxTextGetContent.php",
		data: {"content":content, "title":title},
		success: function(data){
		   $(".wrap_loader").hide();
		   $(".popdiv .pop-content").html(data);
		   $('.pop-modal').show();
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
function save_report_error(){
	var vu = $("#vu").val();
	var url = $(location).attr("href");
	var title = $(document).find("title").text();
	var report_error_description = $("#report_error_description").val();
	var popdiv = $('.popdiv .msg');
	if(report_error_description == ""){
		popdiv.css('color','red');
		popdiv.html('Description is required');
		setTimeout(function () {
			popdiv.html('');
		}, 5000);
		$("#report_error_description").focus();
		return false;
	}
	$(".wrap_loader").show();
	$.ajax({
		type: "GET",
		dataType: "json",
		url: videobaseurl+"/ajaxTextAddReportError.php",
		data: {"vu":vu, "url":url, "title":title, "description":report_error_description},
		success: function(data){
			$(".wrap_loader").hide();
			popdiv.css('color','green');
			popdiv.html(data.msg);
			$('#save_report_error').hide();
			setTimeout(function () {
				popdiv.html('');
			}, 2500);
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
function save_suggestion(){
	var vu = $("#vu").val();
	var url = $(location).attr("href");
	var title = $(document).find("title").text();
	var suggestion_description = $("#suggestion_description").val();
	var popdiv = $('.popdiv .msg');
	if(suggestion_description == ""){
		popdiv.css('color','red');
		popdiv.html('Description is required');
		setTimeout(function () {
			popdiv.html('');
		}, 5000);
		$("#suggestion_description").focus();
		return false;
	}
	$(".wrap_loader").show();
	$.ajax({
		type: "GET",
		dataType: "json",
		url: videobaseurl+"/ajaxTextAddSuggestion.php",
		data: {"vu":vu, "url":url, "title":title, "description":suggestion_description},
		success: function(data){
			$(".wrap_loader").hide();
			popdiv.css('color','green');
			popdiv.html(data.msg);
			$('#save_suggestion').hide();
			setTimeout(function () {
				popdiv.html('');
			}, 2500);
		},
		error: function(){
			$(".wrap_loader").hide();
		}
	});
}
var getUrlParameter = function getUrlParameter(sParam) {
	var sPageURL = window.location.search.substring(1),
		sURLVariables = sPageURL.split('&'),
		sParameterName,
		i;
	for (i = 0; i < sURLVariables.length; i++) {
		sParameterName = sURLVariables[i].split('=');
		if (sParameterName[0] === sParam) {
			return sParameterName[1] === undefined ? true : decodeURIComponent(sParameterName[1]);
		}
	}
};
var edit = getUrlParameter('edit');
if(edit == 1){
	add_notes();
}
function text_bookmark(){
	$(".wrap_loader").show();  
	var title = $(document).find("title").text();
	var vu = $("#vu").val();
	var url = $(location).attr("href");
	$.ajax({
		type: "GET",
		dataType: "json",
		url: videobaseurl+"/ajaxTextAddBookmark.php",
		data: {"vu":vu,"url":url,"title":title},
		success: function(data){  
			successMsg(data.message);
		   	$(".wrap_loader").hide();
		},
		error: function(data){
			console.log(data);
			errorMsg(data.message);
			$(".wrap_loader").hide();
		}
	});
}
function successMsg(msg){
	$(".success_msg").html(msg).show();
	closeMsg();
}
function errorMsg(msg){
	$(".error_msg").html(msg).show();
	closeMsg();
}
function closeMsg(){
	setTimeout(function(){ 
		$(".display_msg").hide();
	}, 3000);
}