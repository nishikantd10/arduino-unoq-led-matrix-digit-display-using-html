const ui=new WebUI();
const input=document.getElementById("digitInput");
const button=document.getElementById("sendBtn");
const statusText=document.getElementById("status");

// ----------------------------
// Connection Events
// ----------------------------
ui.on_connect(()=>{
    console.log("Connected to Uno Q");
    statusText.textContent="Connected";
    button.disabled=false;
});

ui.on_disconnect(()=>{
    console.log("Disconnected");
    statusText.textContent="Disconnected";
    button.disabled=true;
});

// ----------------------------
// Receive messages from Python
// ----------------------------
ui.on_message("display_status",(data)=>{
    statusText.textContent=data.message;
});

// ----------------------------
// Button Click
// ----------------------------
button.addEventListener("click",()=>{
    const digit=parseInt(input.value);
    if(isNaN(digit) || digit<0 || digit>9)
    {
      statusText.textContent="Enter a digit between 0 and 9.";
      return;
    }

    ui.send_message("display_digit",{
        digit: digit
    });
    input.value="";
});

input.addEventListener("keydown",(e)=>{
    if(e.key==="Enter")
    {
      button.click();
    }
});
