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

