const allStories = [
    {
      id: 0,
      author: "Sonny",
      imageUrl: "images/1.jpeg",
    },

    {
      id: 1,
      author: "Sunny",
      imageUrl: "images/2.jpeg",
    },

    {
      id: 2,
      author: "Drake",
      imageUrl: "images/3.jpeg",
    },

    {
      id: 3,
      author: "Mowgli",
      imageUrl: "images/4.jpeg",
    },

    {
      id: 4,
      author: "Piper",
      imageUrl: "images/5.jpeg",
    },

    {
      id: 5,
      author: "Simba",
      imageUrl: "images/6.jpeg",
    },

    {
      id: 6,
      author: "Nala",
      imageUrl: "images/7.jpeg",
    },

    {
      id: 7,
      author: "Dooby Doobs",
      imageUrl: "images/8.jpeg",
    },

    {
      id: 8,
      author: "Biggies",
      imageUrl: "images/9.jpeg",
    },

    {
      id: 9,
      author: "Moroll",
      imageUrl: "images/10.jpeg",
    },
  ];

  const stories = document.querySelector(".stories");
  const storiesFullView = document.querySelector(".stories-full-view");
  const closeBtn = document.querySelector(".close-btn");
  const storyImageFull = document.querySelector(".stories-full-view .story img");
  const storyAuthorFull = document.querySelector(
    ".stories-full-view .story .author"
  );
  const nextBtn = document.querySelector(".stories-container .next-btn");
  const previousBtn = document.querySelector(".stories-container .previous-btn");
  const storiesContent = document.querySelector(".stories-container .content");
  const nextBtnFull = document.querySelector(".stories-full-view .next-btn");
  const previousBtnFull = document.querySelector(
    ".stories-full-view .previous-btn"
  );

  let currentActive = 0;

  const createStories = () => {
    allStories.forEach((s, i) => {
      const story = document.createElement("div");
      story.classList.add("story");
      const img = document.createElement("img");
      img.src = s.imageUrl;
      const author = document.createElement("div");
      author.classList.add("author");
      author.innerHTML = s.author;

      story.appendChild(img);
      story.appendChild(author);

      stories.appendChild(story);

      story.addEventListener("click", () => {
        showFullView(i);
      });
    });
  };

  createStories();

  const showFullView = (index) => {
    currentActive = index;
    updateFullView();
    storiesFullView.classList.add("active");
  };

  closeBtn.addEventListener("click", () => {
    storiesFullView.classList.remove("active");
  });

  const updateFullView = () => {
    storyImageFull.src = allStories[currentActive].imageUrl;
    storyAuthorFull.innerHTML = allStories[currentActive].author;
  };

  nextBtn.addEventListener("click", () => {
    storiesContent.scrollLeft += 300;
  });

  previousBtn.addEventListener("click", () => {
    storiesContent.scrollLeft -= 300;
  });

  storiesContent.addEventListener("scroll", () => {
    if (storiesContent.scrollLeft <= 24) {
      previousBtn.classList.remove("active");
    } else {
      previousBtn.classList.add("active");
    }

    let maxScrollValue =
      storiesContent.scrollWidth - storiesContent.clientWidth - 24;

    if (storiesContent.scrollLeft >= maxScrollValue) {
      nextBtn.classList.remove("active");
    } else {
      nextBtn.classList.add("active");
    }
  });

  nextBtnFull.addEventListener("click", () => {
    if (currentActive >= allStories.length - 1) {
      return;
    }
    currentActive++;
    updateFullView();
  });

  previousBtnFull.addEventListener("click", () => {
    if (currentActive <= 0) {
      return;
    }
    currentActive--;
    updateFullView();
  });