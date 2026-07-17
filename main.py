# SPDX-FileCopyrightText: Copyright (C) Arduino s.r.l. and/or its affiliated companies
#
# SPDX-License-Identifier: MPL-2.0

from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI

# ----------------------------------------------------
# Create the Web UI
# ----------------------------------------------------

ui=WebUI()

# Currently selected digit (default = -1)
current_digit="-1"

# ----------------------------------------------------
# Function called by the Arduino sketch
# ----------------------------------------------------
def get_digit():
    return current_digit

# Register the function with the Bridge
Bridge.provide("get_digit",get_digit)

# ----------------------------------------------------
# Handle messages from the webpage
# ----------------------------------------------------
def on_display_digit(client_id,data):
    global current_digit #'global' used to modify the above 'current_digit' variable which is outside the function
    try:
        digit=int(data.get("digit",0)) #If 'digit' exists, return digit. Else return 0 (default value)
        if 0<=digit<=9:
            current_digit=str(digit)
            print(f"Digit selected: {current_digit}")
            ui.send_message(
                "display_status",
                {
                    "message": f"Displaying digit {current_digit}"
                }
            )

        else:
            ui.send_message(
                "display_status",
                {
                    "message": "Please enter a digit between 0 and 9."
                }
            )

    except Exception:
        ui.send_message(
            "display_status",
            {
                "message": "Invalid input."
            }
        )

# Register the WebSocket handler
ui.on_message("display_digit",on_display_digit) #Whenever the webpage sends a message 'display digit', call the 'on_display_digit' function

# ----------------------------------------------------
# Run the application
# ----------------------------------------------------
App.run()
