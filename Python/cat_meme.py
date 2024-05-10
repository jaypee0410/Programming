import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
import pygame

# Initialize Pygame mixer
pygame.mixer.init()

def open_new_window():
    global new_window  # Declare new_window as global so it can be accessed outside the function
    new_window = tk.Toplevel(root)
    new_window.title("New Window")

    # Load and display the image
    image_path = "cat-laughing-img.png"
    image = Image.open(image_path)
    photo = ImageTk.PhotoImage(image)
    image_label = tk.Label(new_window, image=photo)
    image_label.image = photo  # Keep a reference to prevent image from being garbage collected
    image_label.pack()

    # Bind the closing event of the new window
    new_window.protocol("WM_DELETE_WINDOW", stop_audio_and_close_window)

    # Bind the click event of the image label to close the window
    image_label.bind("<Button-1>", lambda event: stop_audio_and_close_window())
    

    # Load and play the audio file
    audio_file = "cat-laughing-audio.mp3"
    pygame.mixer.music.load(audio_file)
    pygame.mixer.music.play(loops=-1)

    # Bind the closing event of the new window
    new_window.protocol("WM_DELETE_WINDOW", stop_audio_and_close_window)

def stop_audio_and_close_window():
    pygame.mixer.music.stop()
    new_window.destroy()  # Close the new window

def change_volume(volume):
    pygame.mixer.music.set_volume(float(volume) / 100)

# Create the main application window
root = tk.Tk()
root.title("Main Page")

# Add button on main page
button = ttk.Button(root, text="Click Me", command=open_new_window)
button.pack(pady=20)

# Add volume slider on main page
volume_label = ttk.Label(root, text="Volume")
volume_label.pack()
volume_scale = ttk.Scale(root, from_=0, to=100, orient=tk.HORIZONTAL, command=change_volume)
volume_scale.set(50)
volume_scale.pack()

# Start the main event loop
root.mainloop()
