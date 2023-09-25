import tkinter as tk

def add_item():
    item = item_entry.get()
    quantity = quantity_entry.get()
    # Add item and quantity to your data structure here
    result_label.config(text=f"Added: {item} ({quantity})")

# Create the main window
root = tk.Tk()
root.title("Inventory System")

# Create and layout widgets
item_label = tk.Label(root, text="Item:")
item_entry = tk.Entry(root)
quantity_label = tk.Label(root, text="Quantity:")
quantity_entry = tk.Entry(root)
add_button = tk.Button(root, text="Add Item", command=add_item)
result_label = tk.Label(root, text="")

item_label.pack()
item_entry.pack()
quantity_label.pack()
quantity_entry.pack()
add_button.pack()
result_label.pack()

root.mainloop()