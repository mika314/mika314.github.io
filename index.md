---
layout: page
title: Blog
permalink: /
---

{% for post in site.posts limit:10 %}
## <a href="{{ post.url }}">{{ post.title }}</a>
{{ post.content }}
{% endfor %}

<ul>
  {% for post in site.posts offset:10 %}
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
    </li>
  {% endfor %}
</ul>
