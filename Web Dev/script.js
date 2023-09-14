// Smooth scrolling for anchor links
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();

        const targetId = this.getAttribute('href').substring(1);
        const targetSection = document.getElementById(targetId);

        if (targetSection) {
            window.scrollTo({
                top: targetSection.offsetTop,
                behavior: 'smooth'
            });
        }
    });
});

// Animate skill bars when they come into view
const skillBars = document.querySelectorAll('.skill-bar');
const animationDelay = 200; // Adjust this delay as needed

window.addEventListener('scroll', () => {
    skillBars.forEach(skillBar => {
        const skillBarTop = skillBar.getBoundingClientRect().top;
        const screenHeight = window.innerHeight;

        if (skillBarTop < screenHeight - animationDelay) {
            const skillLevel = skillBar.getAttribute('data-level');
            skillBar.style.width = skillLevel;
        }
    });
});

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

//Panel Functions
