import pygame
import tkinter as tk
from tkinter import messagebox
import random

paused = False

# Constants
GRID_SIZE = 20
GRID_WIDTH = 20
GRID_HEIGHT = 20

# Colors
BG_COLOR = "black"
SNAKE_COLOR = "green"
FOOD_COLOR = "red"

pygame.mixer.init()

# Initial snake position and direction
snake = [(5, 5)]
snake_dir = (1, 0)

# Initial food position
food = (10, 10)

# Game mode (True for corner pass, False for no corner pass)
corner_mode = False

# Score
score = 0

# Initialize speed level and MOVE_INTERVAL
speed_level = 1
MOVE_INTERVAL = 100  # Initial interval in milliseconds

#move_sound = pygame.mixer.Sound("pac-man-waka-waka.mp3")
eat_sound = pygame.mixer.Sound("snake_eat.mp3")

# Function to center a window on the screen
def center_window(window, width, height):
    screen_width = window.winfo_screenwidth()
    screen_height = window.winfo_screenheight()

    x = (screen_width - width) // 2
    y = (screen_height - height) // 2

    window.geometry(f"{width}x{height}+{x}+{y}")


# Create the main menu
def main_menu():
    global menu
    menu = tk.Tk()
    menu.title("Snake Game - Main Menu")

    # Center the main menu window
    center_window(menu, 400, 300)

    def start_game():
        menu.destroy()
        create_game_window()

    def show_instructions():
        # Implement instructions screen
        pass

    def show_high_scores():
        # Implement high scores screen
        pass

    def about_me():
        # Implement about me screen
        pass

    def exit_game():
        if tk.messagebox.askokcancel("Exit Game", "Are you sure you want to exit?"):
            menu.destroy()



    start_button = tk.Button(menu, text="Start Game", command=start_game)
    instructions_button = tk.Button(menu, text="Instructions", command=show_instructions)
    high_scores_button = tk.Button(menu, text="High Scores", command=show_high_scores)
    about_me_button = tk.Button(menu, text="About Me", command=about_me)
    exit_button = tk.Button(menu, text="Exit Game", command=exit_game)

    start_button.pack()
    instructions_button.pack()
    high_scores_button.pack()
    about_me_button.pack()
    exit_button.pack()

    menu.mainloop()


# Create a Tkinter window for the game
def create_game_window():
    global corner_mode, snake, snake_dir, food, score, root

    root = tk.Tk()
    root.title("Snake Game")

    # Reset game state
    snake = [(5, 5)]
    snake_dir = (1, 0)
    food = (10, 10)
    score = 0

    # Center the game window
    center_window(root, GRID_WIDTH * GRID_SIZE, GRID_HEIGHT * GRID_SIZE + 30)

    # Make the game window active
    root.focus_force()

    def move_snake():
        global snake, snake_dir, food, score, speed_level, MOVE_INTERVAL

        if not paused:
            # border collision mode
            # new_head = (snake[0][0] + snake_dir[0], snake[0][1] + snake_dir[1])
            # pass through mode
            new_head = (
                (snake[0][0] + snake_dir[0]) % GRID_WIDTH,
                (snake[0][1] + snake_dir[1]) % GRID_HEIGHT
            )

            # Check for collisions
            if (
                    new_head in snake
                    or new_head[0] < 0
                    or new_head[0] >= GRID_WIDTH
                    or new_head[1] < 0
                    or new_head[1] >= GRID_HEIGHT
            ):
                game_over()
                return

            # Move the snake
            snake.insert(0, new_head)

            # Check if the snake ate the food
            if snake[0] == food:
                score += 1  # Increment the score
                eat_sound.play()  # Play the food eating sound
                food = generate_food()

                # Check if the score is a multiple of 5 to increase speed
                if score % 7 == 0:
                    speed_level += 1
                    MOVE_INTERVAL -= 5  # Decrease the interval to make it faster

            else:
                snake.pop()

            # Clear the canvas and redraw the snake and food
            canvas.delete("all")
            canvas.create_rectangle(
                food[0] * GRID_SIZE,
                food[1] * GRID_SIZE,
                (food[0] + 1) * GRID_SIZE,
                (food[1] + 1) * GRID_SIZE,
                fill=FOOD_COLOR,
            )
            for segment in snake:
                canvas.create_rectangle(
                    segment[0] * GRID_SIZE,
                    segment[1] * GRID_SIZE,
                    (segment[0] + 1) * GRID_SIZE,
                    (segment[1] + 1) * GRID_SIZE,
                    fill=SNAKE_COLOR,
                )

            # Update the score display
            score_label.config(text=f"Score: {score}")

        else:
            # Display a message when the game is paused
            canvas.create_text(
                GRID_WIDTH * GRID_SIZE // 2,
                GRID_HEIGHT * GRID_SIZE // 2,
                text="Paused",
                fill="white",
                font=("Helvetica", 24),
            )

        # Schedule the next move
        root.after(MOVE_INTERVAL, move_snake)

    def on_key_press(event):
        global snake_dir, corner_mode, paused
        key = event.keysym
        current_dir = snake_dir

        if key == "Left" and current_dir != (1, 0):  # Prevent going right
            snake_dir = (-1, 0)
        elif key == "Right" and current_dir != (-1, 0):  # Prevent going left
            snake_dir = (1, 0)
        elif key == "Up" and current_dir != (0, 1):  # Prevent going down
            snake_dir = (0, -1)
        elif key == "Down" and current_dir != (0, -1):  # Prevent going up
            snake_dir = (0, 1)
        elif key == "1":
            corner_mode = False
        elif key == "2":
            corner_mode = True
        elif key == "p" or key == "P":
            global paused
            paused = not paused

    def generate_food():
        while True:
            x = random.randint(0, GRID_WIDTH - 1)
            y = random.randint(0, GRID_HEIGHT - 1)
            if (x, y) not in snake:
                return x, y

    def play_again_prompt():
        result = messagebox.askquestion("Game Over", "Do you want to play again?")
        if result == "yes":
            # Restart the game or set up a new game
            root.destroy()
            create_game_window()

        else:
            # Return to the main menu
            root.destroy()
            main_menu()

    def game_over():
        canvas.create_text(
            GRID_WIDTH * GRID_SIZE // 2,
            GRID_HEIGHT * GRID_SIZE // 2,
            text="Game Over",
            fill="white",
            font=("Helvetica", 24),
        )

        # Display the play again prompt
        play_again_prompt()

    canvas = tk.Canvas(
        root, width=GRID_WIDTH * GRID_SIZE, height=GRID_HEIGHT * GRID_SIZE, bg=BG_COLOR
    )
    canvas.pack()

    score_label = tk.Label(root, text=f"Score: {score}", fg="white", bg=BG_COLOR)
    score_label.pack()

    root.bind("<Left>", on_key_press)
    root.bind("<Right>", on_key_press)
    root.bind("<Up>", on_key_press)
    root.bind("<Down>", on_key_press)
    root.bind("1", on_key_press)
    root.bind("2", on_key_press)
    root.bind("p", on_key_press)

    food = generate_food()
    move_snake()

    root.mainloop()


# Show the main menu to start the game
main_menu()
