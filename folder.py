import os

# Define the range for i
start = 11
end = 15

# Define the base name
base_name = "202217b3002"

# Create folders and files
for i in range(start, end + 1):
    folder_name = f"Problem{i}_{base_name}"
    file_name = f"Problem{i}_{base_name}.c"
    
    # Create the folder
    os.makedirs(folder_name, exist_ok=True)
    
    # Create the file inside the folder
    with open(os.path.join(folder_name, file_name), 'w') as file:
        file.write(f"// This is the source file for {file_name}\n")
        
print("Folders and files created successfully.")
