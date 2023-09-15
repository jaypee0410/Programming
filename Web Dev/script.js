// Project filtering
const filterButtons = document.querySelectorAll('.filter-button');
const projects = document.querySelectorAll('.project');

filterButtons.forEach(button => {
    button.addEventListener('click', () => {
        const filter = button.getAttribute('data-filter');

        projects.forEach(project => {
            const projectCategory = project.getAttribute('data-category');

            if (filter === 'all' || projectCategory === filter) {
                project.style.display = 'block';
            } else {
                project.style.display = 'none';
            }
        });
    });
});

// Get a reference to the button element
const backToTopButton = document.getElementById("back-to-top");

// Show or hide the button based on the user's scroll position
window.addEventListener("scroll", () => {
    if (window.pageYOffset > 0) { // Adjust this value as needed
        backToTopButton.style.display = "block";
    } else {
        backToTopButton.style.display = "none";
    }
});

// Scroll to the top of the page when the button is clicked
backToTopButton.addEventListener("click", () => {
    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
});

// Function to check if an element is in the viewport
function isInViewport(element) {
    const rect = element.getBoundingClientRect();
    return (
        rect.top >= 0 &&
        rect.left >= 0 &&
        rect.bottom <= (window.innerHeight || document.documentElement.clientHeight) &&
        rect.right <= (window.innerWidth || document.documentElement.clientWidth)
    );
}

// Get references to the email address and copy button
const emailElement = document.getElementById('email');
const copyButton = document.getElementById('copyButton');

// Add a click event listener to the copy button
copyButton.addEventListener('click', () => {
    // Create a temporary input element
    const tempInput = document.createElement('input');
    
    // Set its value to the email address
    tempInput.value = emailElement.textContent;
    
    // Append the input element to the document
    document.body.appendChild(tempInput);
    
    // Select the input's contents
    tempInput.select();
    
    // Copy the selected text to the clipboard
    document.execCommand('copy');
    
    // Remove the temporary input element
    document.body.removeChild(tempInput);
    
    // Provide visual feedback (e.g., change button text)
    copyButton.textContent = 'Copied!';
    
    // Reset the button text after a short delay
    setTimeout(() => {
        copyButton.textContent = 'Copy';
    }, 2000); // Reset after 2 seconds (adjust as needed)
});