import tkinter as tk
import os

def open_add_item_script():
    # Open another Python script in a new window
    os.system('python Inventory_System/add_item_script.py')

def remove_item():
    # Logic to remove item from inventory
    pass

def update_item():
    # Logic to update item in inventory
    pass

def view_inventory():
    # Logic to display inventory
    pass

# Create main application window
root = tk.Tk()
root.title("Inventory System")

# Get the screen width and height
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()

# Set the window size to 1600x900
window_width = 1600
window_height = 900

# Calculate the position of the window to center it on the screen
x = (screen_width - window_width) // 2
y = (screen_height - window_height) // 2

# Set the window geometry
root.geometry(f"{window_width}x{window_height}+{x}+{y}")

# Make the window resizable
root.resizable(True, True)  # Set both width and height resizable

# Calculate button width and height based on window size
button_width = window_width // 5
button_height = window_height // 10

# Calculate font size based on window size
font_size = min(window_width, window_height) // 35

# Font settings
button_font = ("Tahoma", font_size)

# Add banner label
banner_label = tk.Label(root, text="INVENTORY SYSTEM", font=("Tahoma", 36))
banner_label.pack(side=tk.TOP, pady=20)

# Add buttons for different actions
add_button = tk.Button(root, text="Add Item", command=open_add_item_script, font=button_font, wraplength=button_width)
add_button.pack(side=tk.LEFT, padx=20, pady=20, expand=True, fill=tk.BOTH)

remove_button = tk.Button(root, text="Remove Item", command=remove_item, font=button_font, wraplength=button_width)
remove_button.pack(side=tk.LEFT, padx=20, pady=20, expand=True, fill=tk.BOTH)

update_button = tk.Button(root, text="Update Item", command=update_item, font=button_font, wraplength=button_width)
update_button.pack(side=tk.LEFT, padx=20, pady=20, expand=True, fill=tk.BOTH)

view_button = tk.Button(root, text="View Inventory", command=view_inventory, font=button_font, wraplength=button_width)
view_button.pack(side=tk.LEFT, padx=20, pady=20, expand=True, fill=tk.BOTH)

# Start the main event loop
root.mainloop()
