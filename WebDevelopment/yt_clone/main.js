function playVideo(videoUrl) {
    window.location.href = "video.html?video=" + encodeURIComponent(videoUrl);
}

const params = new URLSearchParams(window.location.search);
const videoUrl = params.get('video');

if (videoUrl) {
    const videoPlayer = document.getElementById('videoPlayer');
    const videoSource = document.getElementById('videoSource');

    videoSource.src = decodeURIComponent(videoUrl);
    videoPlayer.load();
}
