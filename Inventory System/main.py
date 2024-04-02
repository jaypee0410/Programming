import tkinter as tk

def add_item():
    # Logic to add item to inventory
    pass

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

# Add buttons for different actions
add_button = tk.Button(root, text="Add Item", command=add_item)
add_button.pack()

remove_button = tk.Button(root, text="Remove Item", command=remove_item)
remove_button.pack()

update_button = tk.Button(root, text="Update Item", command=update_item)
update_button.pack()

view_button = tk.Button(root, text="View Inventory", command=view_inventory)
view_button.pack()

# Start the main event loop
root.mainloop()
