import tkinter as tk
from tkinter import messagebox

def reverse_text():
    text = input_box.get()
    if not text.strip():
        output_box.config(state="normal")
        output_box.delete(0, tk.END)
        output_box.insert(0, "")
        output_box.config(state="readonly")
        return

    reversed_words = " ".join(word[::-1] for word in text.split())
    output_box.config(state="normal")
    output_box.delete(0, tk.END)
    output_box.insert(0, reversed_words)
    output_box.config(state="readonly")

def copy_output():
    output = output_box.get()
    if output:
        root.clipboard_clear()
        root.clipboard_append(output)
        messagebox.showinfo("Copied", "Output copied to clipboard!")

def reset_all():
    input_box.delete(0, tk.END)
    output_box.config(state="normal")
    output_box.delete(0, tk.END)
    output_box.config(state="readonly")

root = tk.Tk()
root.title("pa1_textreverser.exe")
root.geometry("400x260")
root.resizable(False, False)
root.configure(bg="#d7e6f5")

# Input
input_label = tk.Label(root, text="Input (ex: I LOVE AUTOMATA)", bg="#d7e6f5")
input_label.pack(pady=(15, 5))

input_box = tk.Entry(root, width=40)
input_box.pack()

# Output
output_label = tk.Label(root, text="Output (ex: I EVOL ATAMOTUA)", bg="#d7e6f5")
output_label.pack(pady=(15, 5))

output_box = tk.Entry(root, width=40, state="readonly")
output_box.pack()

# Buttons
button_frame = tk.Frame(root, bg="#d7e6f5")
button_frame.pack(pady=20)

copy_btn = tk.Button(button_frame, text="Copy", width=10, command=copy_output)
copy_btn.grid(row=0, column=0, padx=5)

reset_btn = tk.Button(button_frame, text="Reset", width=10, command=reset_all)
reset_btn.grid(row=0, column=1, padx=5)

reverse_btn = tk.Button(button_frame, text="Reverse", width=10, command=reverse_text)
reverse_btn.grid(row=0, column=2, padx=5)

root.mainloop()
