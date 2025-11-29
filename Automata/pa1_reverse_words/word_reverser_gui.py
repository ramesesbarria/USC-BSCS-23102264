import tkinter as tk  # Tkinter is the standard GUI library for Python


def reverse_letters_in_each_word(text):
    words = text.split()
    reversed_words = []

    for word in words:
        reversed_word = word[::-1]
        reversed_words.append(reversed_word)

    return " ".join(reversed_words)


def main():
    # Create the main window
    root = tk.Tk()
    root.title("Word Reverser")

    # ----- Input label + entry -----
    input_label = tk.Label(root, text="Enter text:")
    input_label.pack(padx=10, pady=5)

    input_entry = tk.Entry(root, width=40)
    input_entry.pack(padx=10, pady=5)

    # ----- Output label + entry (read-only) -----
    output_label = tk.Label(root, text="Reversed text:")
    output_label.pack(padx=10, pady=5)

    # StringVar links a Python variable to a Tkinter widget
    output_var = tk.StringVar()

    output_entry = tk.Entry(root, textvariable=output_var, width=40, state="readonly")
    output_entry.pack(padx=10, pady=5)

    # ----- Button callback -----
    def on_reverse_click():
        # Get the text the user typed
        original_text = input_entry.get()

        # Use your core logic function
        reversed_text = reverse_letters_in_each_word(original_text)

        # Update the output field
        output_var.set(reversed_text)

    # ----- Reverse button -----
    reverse_button = tk.Button(root, text="Reverse", command=on_reverse_click)
    reverse_button.pack(padx=10, pady=10)

    # Start the GUI event loop
    root.mainloop()


if __name__ == "__main__":
    main()
