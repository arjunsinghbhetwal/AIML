import ollama

response = ollama.chat(
    model="qwen3:8b",
    messages=[
        {
            "role":"user",
            "content": "Namaste! Mera name Arjun hai. Mujhe hinglish me reply karo"
        }
    ]
)

print(response["message"]["content"])