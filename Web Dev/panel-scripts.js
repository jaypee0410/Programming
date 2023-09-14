$(function () {
    $(".panel").draggable({
        handle: ".panel-header",
        containment: "body", // Ensure panels stay within the viewport
        stack: ".panel",
    });

    $(".panel").resizable({
        handles: "n, e, s, w, ne, se, sw, nw",
        minWidth: 100, // Minimum width
        minHeight: 100, // Minimum height
    });
});